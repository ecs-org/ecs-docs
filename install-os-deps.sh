#!/bin/bash

plantuml_sha256="e500ea94600ecade4af7262b32ea20a1c884de0013f4a3f07aeae02d594424ab"
need_download=true
if test -e "/opt/plantuml.jar"; then
    echo "$plantuml_sha256 */opt/plantuml.jar" | sha256sum -c -
    if test $? -eq 0; then need_download=false; fi
fi
if $need_download; then
    curl -f -m 120 --connect-timeout 5 -s -S -o /tmp/plantuml.jar http://netcologne.dl.sourceforge.net/project/plantuml/plantuml.8048.jar
    echo "$plantuml_sha256 */tmp/plantuml.jar" | sha256sum -c -
    if test $? -ne 0; then
      echo "error: plantuml checksum missmatch"
      exit 1
    fi
fi

DEBIAN_FRONTEND=noninteractive
if $need_download; then cp -f /tmp/plantuml.jar  /opt/plantuml.jar; fi;
echo -e '#!/bin/bash\njava -jar /opt/plantuml.jar \$@\n' > /usr/local/bin/plantuml
chmod +x /usr/local/bin/plantum
apt-get update -y && apt-get install -y dvipng libjs-mathjax texlive-fonts-recommended texlive-latex-extra texlive-latex-recommended texlive-lang-english texlive-lang-german default-jre curl graphviz python3 python3-setuptools cpp
echo -e \#\!'/bin/bash\ncpp | dot \$@\n' > /usr/local/bin/cpp-dot
chmod +x /usr/local/bin/cpp-dot

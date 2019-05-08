#!/bin/bash

plantuml_url="https://netix.dl.sourceforge.net/project/plantuml/1.2017.15/plantuml.1.2017.15.jar"
plantuml_sha256="c0bf0f8fcfa68de6cb12e8c5c67ec61efffdbfb7ea32974cb8be4a38df94a415"
need_download=true
if test -e "/usr/local/lib/plantuml.jar"; then
    echo "$plantuml_sha256 */usr/local/lib/plantuml.jar" | sha256sum -c -
    if test $? -eq 0; then need_download=false; fi
fi
if $need_download; then
    curl -f -m 120 --connect-timeout 10 -s -S -o /tmp/plantuml.jar "$plantuml_url"
    echo "$plantuml_sha256 */tmp/plantuml.jar" | sha256sum -c -
    if test $? -ne 0; then
        echo "error: plantuml checksum missmatch"
        exit 1
    fi
    cp -f /tmp/plantuml.jar  /usr/local/lib/plantuml.jar
    cat > /usr/local/bin/plantuml <<"EOF"
#!/bin/bash
java -jar /usr/local/lib/plantuml.jar $@
EOF
    chmod +x /usr/local/bin/plantuml
fi

DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get install -y dvipng libjs-mathjax latexmk texlive-fonts-recommended texlive-latex-extra texlive-latex-recommended texlive-lang-english texlive-lang-german default-jre curl graphviz python3 python3-dev python3-setuptools cpp libxml2-dev libxslt-dev zlib1g-dev

cat > /usr/local/bin/cpp-dot <<"EOF"
#!/bin/bash
cpp | dot $@
EOF
chmod +x /usr/local/bin/cpp-dot

if ! which pip3; then easy_install3 pip; fi

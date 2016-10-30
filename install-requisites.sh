#!/bin/bash

# as user
curl -f -m 120 --connect-timeout 5 -s -S -o /tmp/plantuml.jar http://netcologne.dl.sourceforge.net/project/plantuml/plantuml.8048.jar
echo "e500ea94600ecade4af7262b32ea20a1c884de0013f4a3f07aeae02d594424ab */tmp/plantuml.jar" | sha256sum -c -
if test $? -ne 0; then
  echo "error: plantuml checksum missmatch"
  exit 1
fi

# as root
sudo bash -c "cp -f /tmp/plantuml.jar /opt/plantuml.jar; echo -e '#!/bin/bash\njava -jar /opt/plantuml.jar $@\n' > /usr/local/bin/plantuml; chmod +x /usr/local/bin/plantuml"
sudo bash -c "DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get install -y dvipng libjs-mathjax texlive-fonts-recommended texlive-latex-extra texlive-latex-recommended texlive-lang-english texlive-lang-german default-jre curl graphviz python3 python3-setuptools cpp"
sudo bash -c "echo -e \#\!'/bin/bash\ncpp | dot \$@\n' > /usr/local/bin/cpp-dot; chmod +x /usr/local/bin/cpp-dot"

# as user
envdir=~/envdocs
python3 -m venv $envdir
. $envdir/bin/activate
pip install sphinx recommonmark sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-plantuml sphinxcontrib-programoutput sphinxcontrib-seqdiag sphinxcontrib.youtube sphinxcontrib-inlinesyntaxhighlight

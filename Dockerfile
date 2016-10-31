FROM ubuntu:xenial

# locale setup
ENV LANG C.UTF-8
RUN printf %b "LANG=C.UTF-8\nLC_MESSAGES=POSIX\n" > /etc/default/locale
RUN locale-gen en_US.UTF-8 de_DE.UTF-8 && DEBIAN_FRONTEND=noninteractive dpkg-reconfigure locales

# packet caching, need to be updated on install-os-deps.sh changes
RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get install -y dvipng libjs-mathjax texlive-fonts-recommended texlive-latex-extra texlive-latex-recommended texlive-lang-english texlive-lang-german default-jre curl graphviz python3 python3-setuptools cpp

# create user+home, copy source, chown, chmod
ENV HOME /app
RUN adduser --disabled-password --gecos ",,," --home "/app" app
COPY . /app/ecs
RUN chown -R app:app /app
RUN chmod +x /app/ecs-docs/*.sh

# install system dependencies
RUN cd /app/ecs; ./scripts/install-os-deps.sh && apt-get clean -y

# install user dependencies
WORKDIR /app/ecs-docs
USER app
RUN ./scripts/install-user-deps.sh

# build docs as default
EXPOSE 5000
ENTRYPOINT ["/bin/bash", "-c"]
CMD [""]

FROM ubuntu:xenial

# locale setup
ENV LANG C.UTF-8
RUN printf %b "LANG=C.UTF-8\nLC_MESSAGES=POSIX\n" > /etc/default/locale
RUN locale-gen en_US.UTF-8 de_DE.UTF-8 && DEBIAN_FRONTEND=noninteractive dpkg-reconfigure locales

# packet caching, need to be updated on os-deps-ecs-docs.sh changes
RUN DEBIAN_FRONTEND=noninteractive apt-get update -y && apt-get install -y dvipng libjs-mathjax texlive-fonts-recommended texlive-latex-extra texlive-latex-recommended texlive-lang-english texlive-lang-german default-jre curl graphviz python3 python3-setuptools cpp \
  && apt-get clean -y

# create user+home, copy source, chown, chmod
ENV HOME /app
RUN adduser --disabled-password --gecos ",,," --home "/app" app
COPY . /app/ecs-docs
RUN chown -R app:app /app
RUN chmod +x /app/ecs-docs/scripts/*.sh

# install system dependencies
RUN /app/ecs-docs/scripts/os-deps-ecs-docs.sh && apt-get clean -y

# install user dependencies
WORKDIR /app/
USER app
RUN /app/ecs-docs/scripts/user-deps-ecs-docs.sh

# build docs as default
ENTRYPOINT ["/bin/bash", "-c"]
CMD ["/app/ecs-docs/scripts/build-all-ecs-docs.sh"]

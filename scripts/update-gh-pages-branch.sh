#!/bin/bash

is_cleanrepo(){
    repo="${1:-.}"
    if ! git -C $repo diff-files --quiet --ignore-submodules --; then
        echo "Error: abort, your working directory is not clean."
        git  -C $repo --no-pager diff-files --name-status -r --ignore-submodules --
        return 1
    fi
    if ! git -C $repo diff-index --cached --quiet HEAD --ignore-submodules --; then
        echo "Error: abort, you have cached/staged changes"
        git -C $repo --no-pager diff-index --cached --name-status -r --ignore-submodules HEAD --
        return 1
    fi
    if test "$(git -C $repo ls-files --other --exclude-standard --directory)" != ""; then
        echo "Error: abort, working directory has extra files"
        git -C $repo --no-pager ls-files --other --exclude-standard --directory
        return 1
    fi
    if test "$(git -C $repo log --branches --not --remotes --pretty=format:'%H')" != ""; then
        echo "Error: abort, there are unpushed changes"
        git -C $repo --no-pager log --branches --not --remotes --pretty=oneline
        return 1
    fi
    return 0
}


srcpath="$(readlink -e $(dirname $(readlink -e "$0"))/..)"
cd $srcpath
if ! is_cleanrepo; then
  exit 1
fi

# build all to _build
scripts/build-all-ecs-docs.sh

# hard update ./dist on gh-pages branch from current _build
rm -rf /tmp/ecs-dist
cp -r _build /tmp/ecs-dist
git checkout gh-pages
git pull
git reset
rm -rf dist
mv /tmp/ecs-dist dist
> dist/.gitkeep
printf "%b" "FROM nginx\nCOPY dist /usr/share/nginx/html\n" > Dockerfile
git add Dockerfile
git add --all dist
git commit -a -m "Update doc"
git push
git checkout master

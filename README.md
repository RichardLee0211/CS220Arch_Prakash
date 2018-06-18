## course project of cs220 in Binghamton University.
do **not** copy and paste, TAs could catch a copy course project easily.

If you find this repository helpful, please watch, star, fork or leave a
comment. I would like to make it better.

Leave me a comment, wli100@binghamton.edu

## others
find the one that using C and assembly together
```bash
    ➜  cs220mytest git:(master) ✗ find . -iname "*.s"
    ./Lab10/get_ebp.S
    ./F17-A10-RichardLee0211/rotate.S
    ./F17-A10-RichardLee0211/getRBP.S
    ./Lab7/reverse.S
    ./F17-A8-RichardLee0211/run100nops.S
    ./F17-A8-RichardLee0211/toggle.S
    ./F17-A7-RichardLee0211/reverse.S
    ./F17-A7-RichardLee0211/reverse64.S
```
good example in A10

## git commands for submodule
can't learn from tutorial like this: https://git-scm.com/docs/git-submodule
tutorial about submodule, here: https://git-scm.com/book/en/v2/Git-Tools-Submodules
```bash
    # add submodule
    git submodule add <URL>

    # download the submodule
    git submodule init
    git submodule update
    # or download them at once
    git clone --recurse-submodules https://github.com/chaconinc/MainProject

    # check out new work in a submodule
    cd <submodule>
    git fetch
    git merge origin/master
    # or do this
    git submodule update --remote DbConnector

    # track the stable branch instead of master
    git config -f .gitmodules submodule.DbConnector.branch stable
    git submodule update --remote

    # config git diff
    git config --global diff.submodule log
    git diff
    git diff --cache --submodule

    # working on submodule
    git submodule update --remote --merge
    git submodule update --remote --rebase

    # publishing submodule changes
    git push --recurse-submodules=check
    git config push.recurseSubmodules check
    git config push.recurseSubmodules no-demand

    # merging submodule changes
    cd DbConnector/
    git merge 9fd905e
    cd ..
    git add DbConnector
    git commit -am "fast forwarded to a common submodule child"

    # submodule Foreach
    git submodule foreach 'git stash'
```

wait,
when I edit and update the main project, it's fine. It's like any other git repository maintainance
when I edit and update a submodule, I will need to
    0. git check <branchName>
    1. update the submodule to a new commit
        git status in Main project, could see which submodule has new commits
        main project and submodule should have a nice interface, and two parts of code should be separated properly
        tw
    2. tell main repository to use the new commit of submodule
when local edit and upstream edit have conflicts, merge them
and for now, leave "branch&submodule" problem alone
## content
Lab0        git
Lab1        git CONTINUE

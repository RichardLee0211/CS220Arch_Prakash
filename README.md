course project of cs220 in Binghamton University.
--------------------------------------------------------------------------------
do **NOT** copy and paste, TAs could catch a copied course project with eyes closed.

This is just a dead/inactive course project repository.
However, I often look back and preciate how well this course is designed and
how I used to code.
Often referring back to old me would renew my memory about some tricks and
help me become better.

This is a good place for C & Linux programming tricks and GitSubmodule management

content
--------------------------------------------------------------------------------

### projects
| CodeName                   | Desc                                    |
|:---------------------------|:----------------------------------------|
| F17-P1-RichardLee0211      |    poker                                |
| F17-P2-RichardLee0211      |    parse database, student and courses  |
| F17-P3                     |    bomb2.0                              |
| F17-P4-RichardLee0211      |    virtual memory, page                 |

### Assginments

when I wanna create exercise questions set, it could be a good reference

| CodeName                  | Desc                          |
|:--------------------------|:------------------------------|
| F17-A1-RichardLee0211     |      basic bytes operate      |
| F17-A3-RichardLee0211     | String questions              |
| F17-A4-RichardLee0211     | basic c program exercise      |
| F17-A5-RichardLee0211     | Reverse List                  |
| F17-A6-RichardLee0211     | file Header recognizer        |
| F17-A7-RichardLee0211     | reverse funtion in asm        |
| F17-A8-RichardLee0211     | List Sort, CPU Estimator, Toggle.S |
| F17-A10-RichardLee0211    |       macros rotate bt        |
| F17-A12-RichardLee0211    |       mini-shell              |
| F17-A10-RichardLee0211    |       macros rotate bt        |
| ...

### labs

| CodeName                  | Desc                          |
|:--------------------------|:------------------------------|
| Lab0                      | git                           |
| Lab1                      | git CONTINUE                  |
| ...                       |                               |


others
--------------------------------------------------------------------------------
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

git commands for submodule
--------------------------------------------------------------------------------
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
    git config push.recurseSubmodules on-demand

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
```
    0. cd <submodule> && git check <branchName> and do the edit
    1. commit the submodule to a new commit
        git commit -am "this is a new commit of submodule"
        others: main project and submodule should have a nice interface, and two parts of code should be separated properly
    2. tell main repository to use the new commit of submodule
        for main project, submodule is like a file, instead of a fold
        cd ../ && git status in Main project, could see which submodule has new commits
        git add -A && git commit -am "update submoduleA to a new commit"
        git push
```

if we edit local submodule, commit a new commit, then exit and commit in main project, and push main project to upstream,
what heppen is that github will accept this main project commit because it just contain a link to submodule repository with hash number
and because we doesn't push the submodule to github, when we click on the link to submodule in github, 404 happens

when I do git status in submodule, it shows submodule isn't on any branch, but on detached HEAD

is there a way to push all the commits to upstreams ?:
Yes. And now I understand this.
```shell
    git push --recurse-submodule=on-demand
    # or
    git config push.recurseSubmodules on-demand
```

when local edit and upstream edit have conflicts, merge them.
and for now, leave "branch&submodule" problem alone.

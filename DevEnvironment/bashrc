# Put your fun stuff here.

alias home="cd /home/msm"
alias ws="cd /home/msm/projects"
alias gentags="/home/msm/Documents/gentags"

export PATH="$HOME/bin:$PATH"

#To get git branch in our path
parse_git_branch() {
git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/(\1)/'
}
export PS1="\u@ \[\e[32m\]\w \[\e[91m\]\$(parse_git_branch)\[\e[00m\]=> "

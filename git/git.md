# git

- git clone xxx your_repo_name
- git add 
- git  log --oneline
- git restore
- git reset (--hard) log号 重置到了某一版本，丢失中间的过程
- git revert log版本号 回到了某一版本之前，相较与reset，不丢失中间过程
- git checkout -b 分支名 
- git checkout -d 分支名 
- git checkout c1 将引用移动到c1提交
- git merge 
- git tag 别名 log号
- git tag -d



-斐林试剂分离焦虑

origin 对应远程仓库地址

- git remote add origin 远程仓库地址
- https://learngitbranching.js.org/?locale=zh_CN


- git rebase ?
- git rebase -i HEAD~4  
- git cherry-pick 将其他的commit 提交到当前
- git stash


- git branch -f main HEAD~3


-
git commit --amed 指令可以修改最后一次提交的提交信息
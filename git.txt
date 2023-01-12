HTML : 외부로부터 데이터를 요청해서 받기에 중요

JSON : 내가 요청하는 데이터만 딱 받은것.

API : 어플리케이션 프로그래밍 인터페이스

Git : 공동작업 및 버전관리 용이
      
       중앙 집중식 버전관리/분산 버전관리 프로그램		
      
		


버전관리 : 컴퓨터 프로그램의 특정상태를 관리하는 것


git clone url
(깃에 있는거 로컬에 그대로 불러오기)

GUI vs CLI


git init
l
v
git remote add origin2 {remote_repo}
ㄴorigin이라는 이름으로 로컬 리파지토리하고 서버하고 연결해줘 
ㄴorigin이라는 이름 가능한 바꾸지말것
l
v
워킹디렉토리: 내가 작업하고 있는 실제 디렉토리
l
v
git add .
 l
v
스테이징에어리어: 커밋으로 관리하고 싶은 파일이 있는곳
l
v
git commit -m 'message1'
l
v
리포지토리: 커밋들이 저장되는곳
l
v
git push -u origin master(내 브랜치 이름) 



git clone <리모트 리포지토리 주소> 
서버에서 부터 시작할때, 이거 하고 git init 또 하면 안됨

git init   :  local 에서 리파지토리 생성 (git 폴더생성)
git remote add origin <리모트 리포지토리 주소>

git add <파일네임>  : 프로그램 변경됐을때
git add . :stage area로 넘길때
git commit -m"메세지" :커미트 할때

git push origin master   
    git push -u origin master   <-이거 쓰면 2회차부턴 그냥 git push

git pull

git remote -v
연결되어 있는 리모트가 보이는 명령어



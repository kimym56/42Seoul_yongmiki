# 42Seoul_Born2beroot
signature.txt 제출
## Project overview
### Virtual Machine
물리적으로 존재하는 컴퓨터가 아닌, 다른 컴퓨터가 만들어내는 가상의 컴퓨터를 말한다. 

즉 컴퓨터 안에 있는 컴퓨터인 셈이다. 그래서 가상 머신으로 돌린 컴퓨터에서 가상 머신을 돌리는 것도 가능하다.
### Debian OS
1993년 출시한 오픈 소스 및 무료 운영 체제.
- 특징 : 패키지 설치 및 업그레이드 단순함(install 후 Package Manger인 APT 업데이트 방식을 이용하면 SW의 설치나 업데이트에서 다른 패키지와의 의존성, 보안 관련 업데이트 등을 자동으로 설정 및 설치)
- 안정성과 보안에 중점을 두며, 사용자 편리성이 강한 우분투 등 다른 리눅스 배포판의 기반으로 쓰임.
### Debian vs. CentOS
|Debian|CentOS|
|---|---|
|온라인 커뮤니티(데비안 프로젝트에 속한 개인그룹)이 구축 및 지원, 레드햇보다 먼저 배포|2003년까지는 오픈소스, 이후에는 상용된 RHEL(Red Hat Enterprise Linux)의 로고를 지우고 다시 배포한 버전
|무료 개인사용자 서버용을 인기|배포판중에는 가장 인기|
|진입장벽이 낮음|커뮤니티가 아닌 회사에서 관리하므로 패치가 빠르고, 유틸리티 양이 많고, 관리 툴 성능이나 호환성이 좋음|
|패키지 설치 및 업그레이드 단순함|다양하 아키텍처를 지원하지 않음|
|dpkg와APT를 패키지 관리자로 사용|YUM과 DNF를 패키지 관리자로 사용|
|데스크톱 친화적인 GUI 있음|쉬운 GUI가 없음|
### Aptitude vs. APT
Aptitude : 상위 수준의 패키지 관리자.

설치 혹은 삭제 중 충돌 시 마땅한 조치를 제한함.

사용하지 않는 패키지는 자동으로 제거함.

- - -
APT : 다른 상위 수준의 패키지 관리작 사용할 수 있는 하위 수준의 패키지 관리자

패키지 설치 혹은 삭제 중 충돌 시 프로세스가 죽을 수 있음.

사용하지 않는 패키지에 대한 추가적인 옵션 필요함.
### AppArmor
AppArmor는 시스템 관리자가 프로그램 프로필 별로 프로그램의 역량을 제한 할 수 있게 해주는 리눅스 보안 모듈

앱 아머는 정책 파일을 통해 어떤 어플리케이션이 어떤 파일/경로에 접근 가능한지 허용해준다.
enforce 모드와 complain모드 두가지가 존재한다. enforce 모드는 허가되지 않은 파일에 접근하는 것을 거부하는 모드, complain모드는 실질적으로 보안을 제공하는 것은 아니고, 어플리케이션이 해야할 행동이 아닌 다른 행동을 하는경우에 앱 아머는 로그를 남겨준다.
```sh
sudo aa-status // AppArmor 상태확인
```
##Simple Setup
```sh
sudo ufw status // UFW 작동 확인
```
```sh
sudo service ssh status // ssh 작동 확인
```
```sh
uname -srvmo // s : kernel name, r: kernel release info , v: kernel version, m: system hardware type, o : os name 
```
## User
```sh
id username // 유저 정보 확인
// or
getent group sudo
getent group user42
```
password policy 확인 

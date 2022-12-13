# 42Seoul_Born2beroot
signature.txt 제출
## Project overview
### Virtual Machine
물리적으로 존재하는 컴퓨터가 아닌, 다른 컴퓨터가 만들어내는 가상의 컴퓨터를 말한다. 
즉 컴퓨터 안에 있는 컴퓨터인 셈이다. 그래서 가상 머신으로 돌린 컴퓨터에서 가상 머신을 돌리는 것도 가능하다.

원리 : CPU, RAM, 하드디스크 등 컴퓨터의 주요 부품들을 가상으로 만들어서(소프트웨어적으로 구현) 구동하는 식으로 동작한다.
- Host: 실제 컴퓨터, Guest : 가상 컴퓨터
- 시스템 가상머신 (하드웨어 가상머신) : VMware, VirtualBox, Parellels 등
- 프로세스 가상머신 : JVM,PVM,CLR 등

![그림2](https://phoenixnap.com/kb/wp-content/uploads/2021/04/hypervisor-host-os-of-a-virtual-machine.png) 

Hypervisor ex) Virtualbox

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
|패키지 설치 및 업그레이드 단순함|다양한 아키텍처를 지원하지 않음|
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
## Simple Setup
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
#### password policy 확인 절차
```sh
sudo adduser username // 새로운 유저 생성
sudo chage -l username  // 사용자 패스워드 만기 정보
nano /etc/login.defs, nano /etc/pam.d/common-password // 패스워드 정책 수정한 파일
sudo groupadd evaluating  // 그룹 추가 
sudo adduser username evaluating  // 그룹에 유저 추가
id username // 유저 정보 확인
```
- "PASS_MAX_DAYS 30", "PASS_MIN_DAYS 2", "PASS_WARN_AGE 7", "PASS_MIN_LEN 10".
-	"passwd -e 사용자명" 통해 root계정과 현존하는 사용자 계정의 암호 변경을 강제한다. 다음 번 로그인시에 암호를 변경하라고 뜨게 된다.
-	retry=3 : 암호 입력 3회까지
-	minlen=10 : 암호 최소 길이는 10
-	difok=7 : 기존 패스워드와 달라야하는 문자 수는 7
-	ucredit=-1 : 대문자 한 개 이상
-	lcredit=-1 : 소문자 한 개 이상
-	dcredit=-1 : 숫자 한 개 이상
-	reject_username : username이 그대로 또는 뒤집혀서 새 패스워드에 들어있는지 검사하고, 들어있으면 거부
-	enforce_for_root : root 사용자가 패스워드를 바꾸려고 하는 경우에도 위의 조건들 적용


![그림1](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fk.kakaocdn.net%2Fdn%2Fdxh0DJ%2Fbtq53vByUhn%2FU3J7rgVSDIJo4SGuNyIStK%2Fimg.png)
## Hostname and partitions
```sh
hostname // hostname 확인
sudo nano /etc/hostname // hostname 변경
lsblk // 파티션 구조 확인
```
### LVM
Logical Volume Manger : 여러 개의 HDD의 용량을 합쳐서 하나의 파일 시스템으로 구성하는 것.

서버 운영에 있어서 작은 용량의 HDD를 하나로 합쳐 대용량의 스토리지를 구성할 때 사용. 

스토리지 확장 및 변경사항에 있어 유연한 대처가 가능합니다.
## UFW
```sh
sudo ufw status // ufw 상태 확인
sudo ufw allow 8080 // 허용 포트 추가
sudo ufw delete allow 8080 // 허용 포트 삭제
```
Uncomplicated FireWall : Debian 및 Linux 환경에서 작동되는 사용하기 쉬운 방화벽 관리 프로그램.

간단한 명령 및 명령수가 적은 명령줄 인터페이스를 사용하는 것이 특징.

## SSH
```sh
sudo sevice ssh status // ssh 상태 확인
```
Secure SHell Protocol : 네트워크 프로토콜 중 하나. 데이터 전송(Git), 원격 제어(Guacamole)시에 사용

FTP나 다른것과 차이 : 보안
```sh
ssh username@ip -p 2424
```
```sh
sudo vim /etc/ssh/sshd_config // ssh설정 변경(PermitRootLogin)
```
## Script Monitoring
cron : 작업 예약 스케줄러
```sh
crontab -l  // cron 설정 확인
crontab -e  // cron 변경
```

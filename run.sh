#!/bin/sh

restart()
{
  echo 'restart'
  sudo /sbin/shutdown -k now
}

update()
{
  echo 'pull git & restart'
}

i=1
while [ $i -ne 0 ]
do
  echo 'launching rchost'
  ./rchost
  i=$?
  case $i in
    0) echo 'shutdown';;
    1) restart;;
    2) update;;
    *) echo 'invalid return value';;
  esac
echo 'value of i is '$i
done

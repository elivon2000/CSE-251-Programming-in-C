####1、Install ubuntu 14.04（64bit）

#####download it from:
- [ubuntu-14.04-desktop-amd64.iso](http://old-releases.ubuntu.com/releases/trusty/ubuntu-14.04-desktop-amd64.iso)



####2、Install wxWidgets-2.8.12

#####download it from:

- [wxWidgets-2.8.12](https://github.com/wxWidgets/wxWidgets/releases/download/v2.8.12/wxWidgets-2.8.12.tar.gz)

#####Install steps：

######1)Install the dependencies of **wxWidgets**

```
sudo apt install libgtk2.0-dev
```

######2)Unzip and goin the directory of wxWidgets

```
tar xvzf  wxWidgets-2.8.12.tar.gz
cd  wxWidgets-2.8.12
```

######3)Configure wxWidgets

```
./configure --with-regex=builtin --with-gtk --enable-unicode --disable-shared --prefix=/usr/local/wxWidgets
```

######4)Install wxWidgets（cost a long time！）

```
sudo make && make install
```

######5)Dynamic link library settings

5.1)create the wxWidgets.conf file

```
cd /etc/ld.so.conf.d/
sudo touch wxWidgets.conf
sudo gedit wxWidgets.conf &
```

5.2)edit the contents like this：

```
/usr/local/wxWidgets/lib
```

5.3)reload the config

```
sudo ldconfig
```

######6)PATH setting of wxWidgets

6.1)open the setting file

```
sudo gedit /etc/profile &
```

6.2)add the contents below to the end of setting file,save&exit:

```
# wxWidgets
export WXPATH=/usr/local/wxWidgets/
export PATH=$WXPATH/bin:$PATH
```

6.3)reload the setting

```
source /etc/profile
```

######7).check it

```
wx-config --version
```



####3、Install lx11

```
sudo apt-get install libx11-dev
```



####4、compile and execute the source code(take project 2 as an example)

I failed with the original way to compile and run the project.However I did it like this:

```
gcc -c -o elevator.o elevator.c
g++ -o elevator elevator.o -lm libElevatorLib64.a `wx-config --libs` -lX11
./elevator
```




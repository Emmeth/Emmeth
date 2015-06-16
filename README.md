# About Emmeth
>Emmeth = Hebrew word for truth.
>Then you will know the truth, and the truth will set you free. (John 8:32 NIV)

## Vision
Emmeth is a free, open source bible software.
It's purpose is to be free, easy to use.
It supports sermon preparation, daily bible reading, studying, scientific use.
It is multi platform (Windows, Mac, Linux), has a webapp and mobile versions.

## How it works
The bible software comes for free. You can either download the source and compile it or download a stable build for your operating system.
Emmeth has a base software which comes for free all the functions are free of use.
To use it, you need to download in (the base software included) bookstore. 
You need to have an account to download books from the bookstore.
Downloading books is restricted and you need sometimes to purchase the books in order to download them. This is due because of licenses from the authors and the publishers.
Some books are for free, if they are in public domain or under free to use licenses.
Emmeth wants to honor the work of others and respects licenses.
The books, notes and anything else will be synced to your online account.
The purchase can be made through the bookstore and the files will be downloaded and synced automatically.

## Version history
**0.0.1 unstable, pre-alpha**
Still in development, a lot of stuff needs to be done.
It can be forked and added to.

## Documentation
For developers see more in the doc folder.
You can also look at the documentation at the website.
The desktop version is coded in qt for multi platform purpose.

## Compiling from source

### Download from github

Download the zip file of the entire folder.
OR
Clone in Desktop if yo have the github sotware installed.
OR
Clone using command line.
git clone git@github.com:bsesic/Emmeth.git

### using QT
There is a QT .pro file in the src folder, called Emmeth.pro in qEmmeth.
Load it and configure your kits.
Make sure you compile into build or test folder (preferred).

### command line
Needs qmake (from MinGW). Make sure the path is configured correctly.
cd src/qEmmeth
qmake qEmmeth.pro
make
make install

## Folder structure
build - compiled files. Builds for Windows, Mac & Linux go here, stable and nightly.
docs - documentation (mostly developer stuff)
src - source files, also assets, graphics, etc.
test - compiled files used to test development build.
tools - tools for writing, editing, compiling, which is not part of the base system (mostly python). Also plugins.

## Contributing
You like the project?
Do you want to contribute to?
There are many ways to contribute.
1. Code the base software.
2. Code a mobile app for ios or android.
3. Translate the software into your language.
4. Code the web app.
5. Contribute bibles, dictionaries, lexicons, books, maps, images and other stuff.
6. Testing software and reporting bugs.

## Tasks
[ ] translating
[ ] webapp (based on laravel)
[ ] API
[ ] IOS app
[ ] Android app

## Developer(s)
Lead programmer:
Benjamin Schnabel
Tuebingen, Germany

## License
The base software is licensed under the GPL 3 License.
See more here:
http://www.gnu.org/licenses/gpl-3.0-standalone.html
The bibles, books, dictionaries, maps, lexicons and other stuff is not part of the base program and are under the restrictions and licenes of the various authors and publishers.
See more on the website.

## Contact
Website: http://www.emmeth.com
Email: info@emmeth.com

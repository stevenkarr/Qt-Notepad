# Program Overview:
The program is a lightweight notepad application for Windows 7 created using Qt application framework over C++ code. Its purpose is to demonstrate knowledge of the Qt application framework and C++.

## Demonstration of Features:

**New Document**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/1.png)


**Basic Saving**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/2.png)


**Print Document**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/3.png)


**Find and Replace**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/4.png)


**Edit Menu Features**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/5.png)


**Unsaved Changes Confirmation**

![](https://github.com/stevenkarr/Qt-Notepad/blob/master/Demo%20Pictures/6.png)


**Detailed explanation of features:**

* New, Open, Save, and Save As will notify the user if they are about to lose unsaved changes in a confirmation dialog
* The status of whether the document has unsaved changes or not is displayed with an asterisk appended to the file name in the application window's title
* Any dialog will default to the user's home location, but will remember the last accessed location and return there should they open another dialog. For example, the first time tries to save a new document, the save window will default to the user's home directory. Should they save it in "My Documents", the next time they save another document without closing the application the save as window will default to "My Documents".

* Font
    * The user may open a standard font dialog window which will affect the selected text

* Cut, Copy, & Paste
    * The user may cut, copy, and paste the selected text anywhere in the document

* Undo & redo
    * The user may undo and redo operations performed on the document

* Insert Date
    * Inserts as plaintext the current date in the following format: Month DD, YYYY

* About
    * Displays information regarding the application

### Credits:

* Author: Steven Karr
* Date: 11-18-2016

* Application/New icon:
    * Author: gakuseiSean
    * Source: http://findicons.com/icon/23355/notepad?id=23468
* Copy icon:
    * Author: Ruby Software
    * Source: http://findicons.com/icon/26187/copy?id=26197
* Cut icon:
    * Author: Custom Icon Design
    * Source: http://findicons.com/icon/19196/cut?id=19226
* Info icon:
    * Author: Asher
    * Source: http://findicons.com/icon/64637/info?id=362708
* Font ("A") icon:
    * Author: Momenticons
    * Source: http://findicons.com/icon/263329/font?id=263908
* Open icon:
    * Author: David Lanham
    * Source: http://findicons.com/icon/127610/folder_open?id=127697
* Paste icon:
    * Author: Jack Cai
    * Source: http://findicons.com/icon/175974/paste?id=175974
* Redo icon:
    * Author: deviantdark
    * Source: http://findicons.com/icon/203505/edit_redo?id=205051
* Undo icon:
    * Author: deviantdark
    * Source: http://findicons.com/icon/203546/edit_undo?id=398862
* Save icon:
    * Author: Ruby Software
    * Source: http://findicons.com/icon/26193/save?id=26203
* Save As icon:
    * Author: New Mooon
    * Source: http://findicons.com/icon/229845/document_save_as?id=229845
* Find icon:
    * Author: Asher
    * Source: http://findicons.com/icon/86244/search?id=86366
* Calendar icon:
    * Author: Asher
    * Source: http://findicons.com/icon/86283/calender?id=86414
* Print icon:
    * Author: Ahmad Hania
    * Source: http://findicons.com/icon/55433/printer?id=55577

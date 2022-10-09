# WOTS-console_v_tutorial

## 项目地址

欸嘿，还没验收呢，不放链接嗷😎（验收完就放，如果我记得的话…😛

## 开发环境

Ubuntu18（是个Linux都能开发，当然最好Ubuntu，版本高点没关系，反正我没试过🤨

## 整体思路

看到整个项目要求的时候，一堆的菜单和功能总是令人凌乱，不知道从何下手，这里就整体思路来进行一个简要说明：
其实整个项目没有想象中的那么庞大，我们不妨将该项目一分为三：
一、P2P交易系统（就是学生信息管理系统变体）
二、MYSQL，自实现的数据库，自实现指令生成与解析（字符串操作，对P2P交易系统的某些操作追加一层封装）
三、Calculator表达式计算器及合并同类项功能（支持括号及四则运算，输入一个字符串解析计算出结果）
那么之后我们就可以很清晰的知道：**P2P交易系统是整个项目的主体核心，而MYSQL以及表达式计算器是可以基于P2P交易系统的基础上作为附加功能进行追加的**。那么我们的开发流程就变成了：完成P2P交易系统->追加MYSQL实现并对P2P交易系统的某些功能追加一层封装->完成表达式计算器，并将其追加到P2P交易系统。
另外，这里就三个部分实现的核心进行简短说明：
一、P2P交易系统：直接硬写逻辑代码即可，没有任何需要动脑的地方；
二、MYSQL指令自实现与解析：使用正则表达式以及STL string类中的相关方法；
三、表达式计算器：使用BNF范式，递归构造计算树

下面就在了解文件结构之后，开始我们本项目Console版本吧！😏
另外，我墙裂建议你使用Vscode作为代码编辑器，并且安装`ToDoTree`插件，配合爷( •̀ ω •́ )y写的注释简直不要太好用！（安装完成后你便可以在Vscode左侧栏中看到一个打勾勾的小树，点进去，会有惊喜！

## 文件结构说明

注意，这里的文件结构是经过排序的，该顺序实际上也就是我们依次着重开发的顺序，可以参照此顺序来估量自己的进度嗷😃。
另：`General.h`直接给出现成的，注释什么的啥都有，自己研究去吧！😛

```txt
General.h			//全局头文件，用于引用标准库等
main.cpp			//程序入口
System.cpp			//顶层系统类
System.h
Window.cpp			//窗口类
Window.h
IOManager.cpp		//输入输出校验类
IOManager.h
Usr.cpp				//用户类
Usr.h
Merchandise.cpp		//商品类
Merchandise.h
OrderForm.cpp		//订单类
OrderForm.h
Recharge.cpp		//充值记录类
Recharge.h
Calculator.cpp		//表达式计算器类
Calculator.h
SqlItem.cpp			//MYSQL自实现数据库类
SqlItem.h
```

## 项目开发Part1.P2P交易系统

首先我们来开发整个项目的核心，即P2P交易系统，在这个部分，我们就可以实现整个项目的所有功能了，而之后的两个功能无非就是just for fun了！（我才不会告诉你这纯纯就是原本三个毫不相干的项目，生硬地缝合在一起，自己麻烦自己😎，对此我只想说：焯！

### Step1.自顶向下

#### 0x01 什么是tm的系统？哦~，原来这tm的是系统啊！

说到系统，你想到了什么？我想到的就是一个系统，嗯，它就是一个对象，而本项目的程序运行又是什么呢，无非也就是一个叫做“系统”的对象在运行。

:white_check_mark:打开我们的`main.cpp`在`TODO1`中用C语言写下如下操作：（当然，你也可以在真正完成了系统类后再进行到这一步

> 一、自己new一个名为`sys`的对象，该对象为`System`类型（单身🐕没有对象？自己new一个就好了😁;
> 二、调用该对象名为`exec`的方法，虽然暂时没有，但我们将在下一步完成它；
> 三、删除该对象；
> 四、别忘了main低下要`return 0;`

#### 0x02 完成我们的系统

现在，我们来写`System`类，完成我们的名为“系统”的顶层模块：
:white_check_mark:打开`System.h`在这里有一个TODO2，我们需要为系统类添加一些属性和方法：

> 属性：
> :red_circle:`bool`类型，退出引脚，还记得我们前一步写的exec吗，这实际上是一个循环，每次循环我们接收一个用户的操作，然后对用户的操作进行回应，但是当用户要退出循环了怎么办？我们在每次循环时都会检查这个退出引脚，如果其是`true`那么就跳出循环，而后系统对象被删除，程序结束
> :red_circle:`bool`类型，更新引脚，console程序最为麻烦的一点就是：写界面显示麻烦的一匹，因此我们用一个更新引脚，同样每次循环检查一次
> :red_circle:`bool`类型，管理员是否活跃
> :red_circle:`Usr*`类型，指示当前在系统中登录进来的用户
> :red_circle:元素为`Window*`类型的一个栈，这就是我们系统的窗口栈

> 方法：
> :red_circle:返回值为`void`的`exec`，这就是我们系统的消息循环，我们的程序实际上也就是依靠该消息循环跑起来的
> :red_circle:重写类的构造和析构函数

这里对窗口栈来进行简短说明：
如果是面向过程编程，那么对于本项目的需求会有一大堆的菜单和目录层级，很直观的想法就是一个菜单对应于一个函数，进入多层菜单后就是进入函数中的函数…
这样当然也是直观且可行的办法，但是既然使用了OOP何不采取一些更加直观的方法？我们利用系统对象维护一个窗口栈，我们所在的窗口就是该窗口栈顶部的元素，而当我们要进入一个窗口，那么就根据栈顶窗口的分支来new一个新的窗口对象压入到栈中，这样我们当前所在窗口就变成了要进入的新窗口；而当我们要退出的时候，就将栈顶部的窗口弹出并且释放，这样就栈顶就又变成了上一级的窗口，怎么样，妙不妙？😛

:white_check_mark:仔细阅读Window类的接口及实现（我认真的，其实不是我懒得写了x

:white_check_mark:打开`System.cpp`我们现在来初步实现一下`System`类的方法

> 对于构造函数，我们要完成TODO3：
> 一、设置好退出引脚，不至于刚启动就退出；
> 二、将当前系统在线的管理员和用户都清空；
> 三、使用`Window* p = new Window(MAIN_MENU)`来初始化一个主菜单窗口，憋问为什么，CV把这句粘上去就好了，当然如果你看了框架代码，那么一切都很显然；
> 四、将我们刚刚创建好的窗口压入到系统窗口栈当中；

> 对于`exec`函数，我们依照如下逻辑实现TODO4：
> 一、初始展示主菜单，调用`show`方法
> 二、一个循环，每次循环检查退出引脚；
> 三、在循环之内：进入消息分支，获取下一个窗口以及是否退出和是否更新显示（调用栈顶窗口的`branches方法`
> 四、如果进入下一个窗口则new新窗口压入栈中；如果退出则将栈顶窗口弹出并释放；
> 五、如果更新显示则调用栈顶窗口的`show`方法，而后将更新显示复位为`false`

#### 0x03 完成Window类

:white_check_mark:仔细看看`Window.h`当中的各个接口，而后进入`Window.cpp`当中进行实现

> 完成全局变量，即TODO5：
> 参考已有实例填写菜单栏显示数据以及关乎用户选择的正则表达式

> 完成用于显示菜单栏的`show`方法以及消息分支`branches`，即TODO6：
> 一、注意`show`方法的实现过程，我们已经在`IOManager.h`当中提供了如下宏以供直接使用：
> `CLEAR_SCREEN`
> `DRAW_DOUBLE_LINE`
> `OUTPUT`
> 二、注意`branches`的实现，我们已经在`Window.h`中给出了相关接口，你所要作的就是根据当前窗口类型利用选择语句跳转到对应的消息分支调用相应函数即可。

### Step2.完成基础类（用户、商品、订单）

之所以在这一步当中完成用户、商品、订单，是由于之后的所有功能都离不开这三个基本的类。当完成了基础的、最常用的类之后，我们再来开发更加高层的功能就能够非常顺利。

#### 0x01 基本完成用户类及部分方法

在这一部分，我们需要基本完成用户类并完成相关方法，请注意`Usr.h`当中包含了用户类的所有数据成员和方法接口，并且附有详细的功能注释，建议熟悉各个API后再进行下一步。

这里我们要对用户类中除了文件IO的两个方法之外的所有方法进行实现，请移步到`Usr.cpp`当中，根据API的功能要求完成所有的带有`TODO7`注释的函数逻辑实现。
另外友好地进行提醒：在全局变量初始化部分，墙裂建议为链表头指针追加哨兵节点以简化链表操作，该建议在后面的商品类、订单类、充值类中同样适用

#### 0x02 基本完成商品类及部分方法

与用户类类似，首先阅读`Merchandise.h`当中的注释和API，而后进入`Merchandise.cpp`里实现除文件IO的两个方法之外的所有带有`TODO8`注释的函数逻辑实现。

#### 0x03 基本完成订单类及部分方法

阅读`OrderForm.h`当中的注释和API，而后进入`OrderForm.cpp`里实现除文件IO的两个方法之外的所有带有`TODO9`注释的函数逻辑实现。

### Step3.完成各个菜单条目中的功能

在完成了基本类之后，我们可以来对各个菜单条目当中的功能进行逐一实现，值得注意的是，在实现功能的过程当中你可能会发现先前实现的基本类当中的bug😎
注意：我们可以在`Window.cpp`当中找到指定分支，按住`Ctrl`键的同时点击函数以快速转到相应函数的定义处进行实现。

#### 0x01 实现管理员登录（TODO10）

在`IOManger.cpp`当中的`admin_login`函数实现，无特别注意，建议适用`IOManager`类以`show`开头的方法展示提示信息、成功信息以及错误信息，另外通过库函数`sleep`和宏`DELAY`延迟显示以使得展示的成功/错误信息能被用户短暂看见，后续的实现同样如此建议你们这么做🤐。

#### 0x02 实现用户注册（TODO11）

在`IOManager.cpp`当中的`usr_register`函数实现，注意我们需要首先实现用户名校验相关的`check_ch_en_input`函数以及`check_lowen_num_input`函数，注意这些函数定义均在`IOManager.cpp`当中。
另外：除用户名、用户密码格式检验外，我们还需要注意该用户名是否为空、该用户名是否已被注册，并且还要将该用户添加到用户列表当中（即Usr类的静态成员维护的一个链表）。且用户输入和成功/错误信息的显示需要在本函数中实现，函数返回值表示用户注册是否成功。

#### 0x03 实现用户登录（TODO12）

在`IOManager.cpp`当中的`usr_login`函数实现，注意检查用户是否存在、用户是否被封禁。
当完成这一步后，你可以结合用户注册和用户登录来简单检验一下当前实现的正确性。

#### 0x04 实现卖家基本功能（TODO13）

该条目下有多个功能需要实现：
1.发布商品，在`IOManager.cpp`当中的`add_merchandise`函数中进行实现，请注意对商品各项信息是否符合规范的校验；
2.查看发布商品，在`IOManager.cpp`当中的`usr_seller_menu_branches`对应分支中进行实现（不过我更推荐你将其封装成一个函数）；
3.修改商品信息，在`IOManager.cpp`当中的`modify_merchandise_info`函数中进行实现；
4.下架商品，在`IOManager.cpp`当中的`usr_remove_merchandise.cpp`函数中进行实现；
5.查看历史订单，在`IOManager.cpp`当中的`usr_seller_menu_branches`对应分支中进行实现（同样推荐你将其封装成一个函数）

注意：在功能2、5实现当中，我推荐你使用`system("pause")`或者是`cin.clear(); getpass();`来实现按下任意键退出的功能，以供展示的信息能够被长久显示。
当你完成了上述所有任务或部分任务，墙裂建议运行程序执行一些操作以进行正确性检验。

#### 0x05 实现买家基本功能（TODO14）

该条目下同样有多个功能需要实现😄:
1.查看商品列表，在`IOManager.cpp`当中的`usr_buyer_menu_branches`对应分支中进行实现;
2.购买商品，在`IOManager.cpp`当中的`purchase_merchandise`函数中进行实现；
3.搜索商品，在`IOManager.cpp`当中的`usr_search_merchandise`函数中进行实现；
4.查看历史订单，在`IOManager.cpp`当中的`usr_buyer_menu_branches`对应分支中进行实现；
5.查看商品详细信息，在`IOManager.cpp`当中的`usr_show_merchandise_details_info`函数中进行实现；

注意：在功能2的实现中要注意以下问题：商品是否存在，商品是否下架，商品是否售罄，商品是否是自己发布的，是否有足够的商品满足购买数量，是否有足够的余额进行购买，商品卖出后商品数量需要改变，商品卖出后买家花了钱，商品卖出后卖家赚了钱，商品卖出后增加了订单。

#### 0x06 实现用户信息菜单基本功能（TODO15）

该条目下有多个功能需要实现：
1.查看信息，在`IOManager.cpp`当中的`show_specific_usr_details_info`函数中进行实现；
2.修改信息，在`IOManager.cpp`当中的`modify_usr_info`函数中进行实现；
3.充值，在`IOManager.cpp`当中的`usr_recharge`函数中进行实现；

#### 0x07 实现管理员基本功能（TODO16）

该条目下有多个功能需要实现：
1.查看所有商品，在`IOManager.cpp`当中的`admin_menu_branches`对应分支中进行实现；
2.搜索商品，在`IOManager.cpp`当中的`admin_search_merchandise`函数中进行实现；
3.下架商品，在`IOManager.cpp`当中的`adminn_remove_merchandise`函数中进行实现；
4.查看所有订单，同功能1；
5.查看所有用户，同功能1；
6.封禁用户，在`IOManager.cpp`当中的`admin_ban_usr`函数中进行实现；

以上所有功能实现的正确性均需要自己手动进行操作测试哦😆（憋问，问就是懒狗😠，不想配单元测试上来了

### Step4.文件IO实现数据持久化存储（TODO17）

现在我们基本完成了P2P交易系统的基本功能，但是每当我们关闭了程序之后，下一次打开程序后所有的用户、商品、订单又重归于无，还记得我们在实现基本类（step2）里未实现的文件IO函数吗，这里就来实现它们实现数据的持久化存储😏

在`Recharge.cpp`当中的两个文件IO函数已经提供了一个很好的示例，可以仿照其完成下述文件当中的TODO17条目：
`Usr.cpp`
`Merchandise.cpp`
`OrderForm.cpp`

至此，我们的P2P交易系统就成功完成了！🤣

## 项目开发Part2.MYSQL数据库

在实现流程中的条件编译可以使得我们开发过程和分支更加清晰，在实现了MYSQL之后，我们只需要在`General.h`中将名为`MYSQL`的宏打开，之后便可以启用我们自实现的“数据库”了。

MYSQL的实现实际上在本项目中毫无实际意义，浪费计算资源，增加实现复杂度等等等，因此在这也不做过多的赘述，只是就实现思路进行复盘：
实现无非就是在原有的对于用户列表、商品列表、订单列表的搜索、添加、修改操作之上追加一层封装，指令的实现和解析则通过`string`类的相关方法以及正则表达式进行实现，进而依靠指令解析后的结果转入到对应的分支进行执行，而在实现了我们的数据库类之后，我们只需要在需要对用户、订单、商品进行增加、修改、查找的地方通过条件编译相关的宏，将原本的直接操作替换为MYSQL的相关接口调用即可。

## 项目开发Part3.Calculator表达式计算机及合并同类项化简

表达式计算器的实现原理在我的另一篇文章中有提及：
[PA-实现四则运算 · pawx2's Studio](https://pawx2.github.io/2022/01/16/实现四则运算/)

这里所采用的是BNF范式，相比于栈实现的中缀表达式转后缀表达式再用栈和符号优先级进行计算，BNF范式结合递归的实现策略能够有更加强大易用的拓展性和更多可能性的、便捷的错误报告和检测方式，个人认为更加优秀。
如果要细究实现细节，建议查看相关源代码。

## 最后

这篇tutorial说是tutorial，实际上更像是对自己第二次做P2P交易系统/学生信息管理系统的一次复盘，整个项目和文章从无到有都并不是一开始脑袋中就有完整的蓝图，而是边做边改最后所形成的。
第一次做P2P交易系统是在大一的程序设计基础实验课上，整个过程同样犹如“坐牢”，曾经因为两个IO函数接口就琢磨了一整天还不会使，也算是走了不少的弯路，最后项目也做出来了，拓展功能也完成了，当时完成后并没有任何的欣喜，所有的只是松了一口气，并不满足，仅此而已，因为当初也仅仅只是摸着石头过河把Console程序写了出来，并且臃肿和简陋。
而第二次就是这一次了，这是高级程序设计课上的第一个大的project，实际上也是当年程序设计基础实验课的三个项目缝合在一起，这个项目令人熟悉而陌生，在花费了3天时间从一头雾水到完成Console版本之后，深深感觉第一次做的时候写下的“屎山代码”之恶心，也感慨学习计算机一年以来自己的能力已经和从前大不相同，不仅仅是代码的能力，更多的还有阅读文档，查找资料的能力。大一时找两个接口的使用方法，我用了一整天，而这一次，我却能在一天之内查询到不知道多少个接口并快速地将其运用起来。
在完成了Console版本之后的三天，我又马不停蹄地将Linux下开发的Console源代码移植到Windows下的Qt，原本以为移植到一个框架中仅仅只是一天的事，但却没想到有一堆的接口等问题，加上UI布局等等额外扩展出的东西，大差不差也算是重新从头来了一遍，虽说花了时间，但也完成了代码的重构，当最后看到自己的窗口化程序运行了起来，心中确确实实地会有“孩子出生了”的大欣喜，也更加激发了对于计算机的兴趣。
想想一年前，程序完成的松一口气，和如今程序完成后的欣喜，总是令人感慨学习的路还很长，学习的东西、应用的东西越多，所能获得的“掌控感”就越大，从而越能为之欣喜，为之鼓舞😏

最后的最后，祝你也能找到自己感兴趣之事，将自己所作的变成自己所爱的。嗯，写得手累死了，润！😛



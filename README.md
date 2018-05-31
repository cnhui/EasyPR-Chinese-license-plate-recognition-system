# EasyPR-Chinese-license-plate-recognition-system
ARM Linux下EasyPR中文车牌识别系统开发

1、当你下载这个EasyPR的时候，请你看一下README.md说明和ARM Linux下EasyPR中文车牌识别系统开发.doc文档,这都是本人亲测的并可以运行！

2、EasyPR-master-pc.zip是在Linux服务器训练SVM模型和ANN模型，EasyPR-master-arm是在arm开发板是进行车牌检测和识别，这两个版本均可以运行！

3、原源码版本，做对比学习未修改！
3.1、easypr-EasyPR-master.zip---2015年左右的老版本，可以在VS2013上运行！
EasyPR是一个中文的开源车牌识别系统，其目标是成为一个简单、高效、准确的车牌识别引擎。
相比于其他的车牌识别系统，EasyPR有如下特点：
它基于openCV这个开源库。这意味着你可以获取全部源代码，并且移植到java等平台。
它能够识别中文。例如车牌为苏EUK722的图片，它可以准确地输出std:string类型的"苏EUK722"的结果。
它的识别率较高。图片清晰情况下，车牌检测与字符识别可以达到90%以上的精度。

版本
EasyPR最开始是发布在GitHub上的，然后在国内的oschina上也部署了一份镜像。 相关的issue欢迎在GitHub上统一提交。

兼容性
EasyPR是基于opencv2.4.8版本开发的，2.4.8以上的版本应该可以兼容，以前的版本可能会存在不兼容的现象。opencv3.0的版本还没有经过测试。

安装
EasyPR不需要安装，开发者直接在其上做改动。如果想使用DLL形式引用或者使用其他语言调用，则可以在EasyPR_DLL_src中找到。

使用
使用Git克隆一份拷贝到你本机或者直接下载zip压缩吧。使用vs2010或以上版本的IDE选择“从现有代码创建项目”，引用EasyPR的目录。

===========================

3.2、EasyPR-master
本次更新版本是1.6正式版本，主要有以下几点更新：

    修正了多项readme的文本提示。

    增加了C#调用EasyPR的一个项目的链接，感谢 @zhang-can 同学。

注意

    对于Opencv3.2或以上版本，如果碰到编译问题，例如“ANN_MLP”相关的错误，尝试将config.h中将#define CV_VERSION_THREE_ZERO改为#define CV_VERSION_THREE_TWO试试.

    linux系统推荐使用Opencv3.2以上版本。3.2以下的版本例如3.0和3.1在识别时可能会出现车牌识别结果为空的情况。稳妥起见，建议都升级到最新的3.2版本。Windows版本没有这个问题。

EasyPR特点：
    它基于openCV这个开源库。这意味着你可以获取全部源代码，并且移植到opencv支持的所有平台。
    它能够识别中文。例如车牌为苏EUK722的图片，它可以准确地输出std:string类型的"苏EUK722"的结果。
    它的识别率较高。图片清晰情况下，车牌检测与字符识别可以达到80%以上的精度。
	
4、如果对EasyPR还不了解，请参考：
4.1、中文车牌识别系统，源码Git地址为：https://github.com/liuruoze/EasyPR
4.2、EasyPR--中文开源车牌识别系统 开发详解（1）： http://www.cnblogs.com/subconscious/p/4001896.html

============================
The English version

1. When you download this EasyPR, please check the readme. md instructions and the development of the Chinese EasyPR license plate recognition system under ARM Linux.

2. Easypr-master-pc-zip trains the SVM model and ANN model in the Linux server, while easypr-master-arm trains the license plate detection and recognition in the arm development board, both of which can run!

3. Original source version, do comparison learning unmodified!
3.1 easypr- easypr- master. Zip - old version around 2015, can be run on VS2013!
EasyPR is an open source license plate recognition system in Chinese. Its goal is to become a simple, efficient and accurate license plate recognition engine.
Compared with other license plate recognition systems, EasyPR has the following features:
It is based on the open source library, openCV.This means you can get all the source code and port it to platforms like Java.
It can recognize Chinese.For example, a picture with a license plate of su EUK722 can accurately output the result of STD :string type "su EUK722".
It has a high recognition rate.When the picture is clear, license plate detection and character recognition can reach more than 90% accuracy.

version
EasyPR was first released on GitHub, and then a mirror was deployed on oschina in China.Relevant issues are welcome to be submitted on GitHub.

compatibility
EasyPR was developed based on version 2.4.8 of opencv2.4.8. Versions above 2.4.8 should be compatible, and previous versions may be incompatible.The version of opencv3.0 has not been tested.

installation
EasyPR doesn't need to be installed; developers make changes to it.You can find it in EasyPR_DLL_src if you want to refer to it as a DLL or call it in another language.

use
Use Git to clone a copy to your local machine or download the zip compression directly.Use vs2010 or more ides to select create projects from existing code, referencing the EasyPR directory.
= = = = = = = = = = = = = = = = = = = = = = = = = = =
3.2, EasyPR - master
The updated version is 1.6 official version, which has the following updates:
Fixed multiple readme text prompts.
Added a link to a project of C# calling EasyPR, thanks to @zhang-can.

Pay attention to
For Opencv3.2 or above, try changing #define CV_VERSION_THREE_ZERO to #define CV_VERSION_THREE_ZERO in config.h to #define CV_VERSION_THREE_TWO if you encounter compilation problems, such as "ANN_MLP" related errors.

Linux systems recommend Opencv3.2 or above.3.2 for the following versions, such as 3.0 and 3.1, license plate recognition results may be empty during recognition.To be on the safe side, it is recommended to upgrade to the latest version 3.2.The Windows version does not have this problem.

EasyPR features:
（1）It is based on the open source library, openCV.This means you can get all the source code and port it to all the platforms that opencv supports.
（2）It can recognize Chinese.For example, a picture with a license plate of su EUK722 can accurately output the result of STD :string type "su EUK722".
（3）It has a high recognition rate.When the picture is clear, license plate detection and character recognition can reach more than 80% accuracy.

4. If you are not familiar with EasyPR, please refer to:
4.1, Chinese license plate recognition system, source Git address is: https://github.com/liuruoze/EasyPR
4.2, EasyPR - Chinese open source license plate recognition system development steps (1) : http://www.cnblogs.com/subconscious/p/4001896.html

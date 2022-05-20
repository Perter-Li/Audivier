# Audivier

#### 介绍

该课题是一个桌面端本地音视频播放器，主要功能是播放视频、音频，管理音视频文件列表等。

**featureUI分支**：主要进行UI界面的显示。

**presentation分支**：主要之后进行有关高级功能的实现，各个功能与featureUI分支对接。



#### 基础功能

1. **音视频播放**

   1. 支持播放主流的mp4、flv等格式的视频，视频播放帧率不低于30
   2. 支持播放主流的mp3等格式的音频，支持从音频文件中提取出专辑封面文件作为预览图（部分音频资源具备）
   3. 支持全屏播放

2. **音视频播放控制**

   

3. 提供一个音量控制滑杆，用于控制播放音量

4. 提供一个播放进度滑杆，用于展示当前播放进度

5. 提供上一首、下一首、播放or暂停按钮，用于控制播放

6. 提供一个切换播放模式的控制按钮，支持只播放当前、顺序播放、随机播放、单个循环播放

7. 提供一个全屏or小屏播放切换按钮，全屏播放时，鼠标移动需要在视频上面展示音视频播放控制小控件，超过5s鼠标不动小控件自动隐藏

8. 支持快捷键草稿

   1. 空格键 播放或暂停
   2. Ctrl+F 全屏或小屏
   3. Ctrl+I 唤起资源导入弹窗
   4. Ctrl+⬅️ 上一首
   5. Ctrl+➡️ 下一首
   6. Ctrl+⬆️ 增加音量
   7. Ctrl+⬇️ 降低音量

3.**媒体库**

1. 支持一个媒体库播放列表，支持拖拽或者点击导入按钮进行导入音视频文件
2. 播放到媒体库中的对应视频需要有高亮或者选中态等提示
3. 媒体库列表支持本地缓存，下次启动时需要恢复上一次的列表。存在资源被移动等情况需要有对应的丢失态提示

4.**程序安装包**

1.  支持将整个程序打包成一个安装包程序，安装后在桌面创建一个快捷方式，达到在任意电脑上都能安装和使用

2.  

【挑战⭐️】支持查看媒体信息

1.  右键媒体库列表文件或者其他方式，可以查看文件的详细信息，包括：

2.  文件名
3.  视频码率、帧率、编码格式、分辨率等等
4.  音频码率、编码格式、声道数、专辑信息、演唱者信息等等

【挑战⭐️⭐️】支持进度微调

1. 下一帧、上一帧快捷键操作
2. 下5帧、上5帧快捷键操作

【挑战⭐️⭐️⭐️】支持倍速播放

1.  支持2倍、4倍、8倍的倍速播放

【挑战⭐️⭐️⭐️⭐️】进度条支持预览对应位置的视频缩略图

1.  鼠标停留在进度条的任意位置，展示对应时间点的视频帧缩略图

【挑战⭐️⭐️⭐️⭐️⭐️】支持视频倒放

1.  支持视频倒放，倍速倒放

【挑战⭐️⭐️⭐️⭐️⭐️】支持展示音频波形图

1.  音频播放过程，支持展示波形变化图



基础要求

1. 具备基本的功能

1. 良好的UI视觉、交互设计

1. 播放不卡顿

1. 功能主路径无闪退
# artifact-impact
A [Genshin Impact] artifacts enhancement estimator. 一个【原神】圣遗物强化预测工具。
- Recorder配置和启动方式：
  1. 解压.zip文件；
  2. 访问解压完成后的文件夹；
  3. （Windows用户需先安装Cygwin并将Cygwin添加至系统环境变量）双击运行Recorder程序。
- Estimator配置和启动方式：
  1. 解压.zip文件；
  2. 访问解压完成后的文件夹下的dist文件夹；
  3. 双击运行Estimator程序。

# _Artifact Impact - Estimator v1.0正式版现已在双端推出_
July 18, 2021\
从此不再盲目选择强化圣遗物。输入未强化的圣遗物的各项数据，得到预测的强化满级的词条数据。从而有远见地选择优质的圣遗物进行强化，同时节约强化素材。请访问Releases。

# _关于Estimator v1.0在启动时和运行中_
July 18, 2021\
由于软件依赖包体积较大，某些设备在每次启动软件之初会经历明显的加载时间，请不要在窗口内进行任何操作并耐心等待约5～60秒（等待时长随设备性能变化）。\
出现关于TensorFlow的Warning可以忽略，不会影响Estimator的正常使用。

# _Record Helper现已更名为Recorder_
July 12, 2021\
用便捷小巧的方式记录圣遗物的强化数据，并转换为特定的文件类型以便在后续的研发中使用。请访问Releases。

# Estimator v1.0
July 18, 2021
- 【重要】相较v1.0-beta，v1.0正式版预测的结果的准确率提高了约11%。
- 【重要】现在可以在同一个Estimator进程中预测多个圣遗物的强化数值了。
- 优化了在MacOS系统上的运行表现。
- 操作界面以控制台模式。
- 支持双暴总和数值预测。
- 支持MacOS与Windows系统。
- 预测值仅供参考，后续版本更新会继续优化预测值。

# Estimator v1.0-beta（已结束）
July 17, 2021
- 操作界面以控制台模式。
- 支持双暴总和数值预测。
- 本次测试支持MacOS与Windows系统。
- 预测值仅供参考，后续版本更新会优化预测值。

# Recorder v1.2 (原Record Helper)
July 12, 2021
- 【重要】重启对Windows系统的支持，但需具备Cygwin环境。
- 优化了底层逻辑，现采用C++17及以上标准。
- 优化了数据采集的维度，现在只会记录十种副词条。
- 优化了显示界面，列表的结构变得更为清晰了。
- 支持MacOS及Windows系统。

# Record Helper v1.2-beta（已结束）
July 12, 2021
- 优化了数据采集的维度，现在只会记录十种副词条。
- 优化了显示界面，列表的结构变得更为清晰了。
- 此Beta测试版本目前仅支持Unix系统。

# Record Helper v1.1
July 12, 2021
- 【重要】修复了过去的残留数据有几率会延续到新数据中的Bug。
- 新增了录入至总合文件功能，现在新录入的任何数据都会同时添加至combined目录中。
- 优化了显示界面。
- 仅支持Unix系统，由于依赖环境的问题暂停对Windows系统的支持。

# Record Helper v1.1-beta（已结束）
July 12, 2021
- 新增了录入至总合文件功能，现在新录入的任何数据都会同时添加至combined目录中。
- 优化了显示界面。
- 此Beta测试版本目前仅支持Unix系统。

# Record Helper v1.0
July 11, 2021
- 操作界面为控制台模式。
- 支持Unix以及Windows系统。

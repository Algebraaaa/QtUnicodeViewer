# Qt 字符编码与属性演示小程序
# 项目名称

本项目是基于《Qt6 C++开发指南》中的示例练习而完成的 Qt 小项目，主要用于学习和交流，更多内容推荐购买原书  
原书作者：王维波  
出版信息：人民邮电出版社
> ⚠️ 本项目仅用于学习参考，非商业用途。

本项目是一个基于 **Qt Widgets** 的小型字符处理与编码演示工具。
通过界面按钮操作，可以查看字符串中每个字符的 Unicode 编码，判断字符类型（数字、字母、符号等），并演示字符编码与转换的基本操作。

---

## 🧩 功能概述

| 功能按钮                             | 功能说明                                |
| -------------------------------- | ----------------------------------- |
| **获取字符串字符信息** (`btnGetChars`)    | 遍历输入字符串中每个字符，显示其 Unicode 编码。        |
| **字符属性判断** (`btnCharJudge`)      | 判断输入字符是否为数字、字母、标点符号、空格等。            |
| **清空输出** (`btn_Clear`)           | 清除输出框内容。                            |
| **Latin1 编码转换** (`btnCovLatin1`) | 演示 `QChar::fromLatin1()` 的使用。       |
| **UTF16 编码转换** (`btnCovUTF16`)   | 演示 `QChar::fromUcs2()` 的使用。         |
| **字符替换示例** (`btnCompare`)        | 将字符串中的指定字符替换为另一字符，演示 `QChar` 比较与替换。 |

---

## 💡 主要代码逻辑说明

### 1. 自动信号与槽连接（Auto-Connection）

Qt 支持按命名约定自动连接信号与槽。
当槽函数命名为 `on_控件名_信号名()` 格式时，`setupUi()` 会自动建立连接，无需手动 `connect()`。

```cpp
void Widget::iniSignalSlots()
{
    // 如果使用 Qt Designer 的命名规则，以下手动连接可省略
    // connect(ui->btnGetChars, &QPushButton::clicked, this, &Widget::on_btnGetChars_clicked);
}
```

---

### 2. Unicode 显示示例

```cpp
QChar ch = str.at(i);
char16_t uniCode = ch.unicode();
QString info = QString(ch) + QString::asprintf("\tUnicode=0x%X", uniCode);
ui->plainTextEdit->appendPlainText(info);
```

---

### 3. 字符判断函数示例

```cpp
ui->checkDigit->setChecked(ch.isDigit());
ui->checkLetter->setChecked(ch.isLetter());
ui->checkUpper->setChecked(ch.isUpper());
ui->checkLower->setChecked(ch.isLower());
ui->checkSymbol->setChecked(ch.isSymbol());
```

---

## 🛠️ 开发环境

| 项目        | 说明                                  |
| --------- | ----------------------------------- |
| **Qt 版本** | Qt 5.x 或 Qt 6.x 均可                  |
| **编译器**   | MSVC / MinGW                        |
| **开发环境**  | Qt Creator 或 Visual Studio（带 Qt 插件） |
| **语言标准**  | C++98 及以上                           |

---

## 📁 文件结构

```
├── widget.h / widget.cpp      # 主窗口逻辑代码
├── main.cpp                   # 程序入口
├── widget.ui                  # Qt Designer 界面文件
├── .pro     # 构建配置文件
└── README.md                  # 项目说明文件
```

---

## 🚀 运行效果
<img width="406" height="366" alt="0f16cb041a4e9ca1aec12396f8521d16" src="https://github.com/user-attachments/assets/049d41ce-fc76-4c8e-8201-baca04d3fb79" />

* 输入一个字符串 → 点击【获取字符信息】→ 查看每个字符及其 Unicode 编码
* 输入单个字符 → 点击【字符判断】→ 查看该字符的各种属性
* 点击其他按钮可体验不同编码与字符替换效果





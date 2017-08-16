#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "./src/Dictionary.h"
#include "./src/Word.h"
#include "./src/Recite.h"
#include "./src/History.h"
#include "./src/Translation.h"
#include "./src/Test.h"
#include "./src/TestList.h"
#include <string>
#include <sstream>
#include <QFileDialog>
#include <QMessageBox>

Dictionary *dict = new Dictionary();
History *hist = new History();
History *recitelist = new History();
History *wordlist = new History();

MainWindow::MainWindow(std::string username, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), username(username)
{
    ui->setupUi(this);
    setFixedSize(726,547); // 禁止改变窗口大小。
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_queryButton_clicked()
{
    QString query = ui->lineEdit->text();
    std::string stdquery = query.toStdString();
    std::string meaning = dict->getMeaning(stdquery);
    std::string example = dict->getAllExample(stdquery);
    int difficult = dict->getDegree(stdquery);

    std::stringstream in;
    in << difficult;
    std::string diff = in.str();

    if(dict->isExisted(stdquery)) hist->addWord(Word(stdquery, meaning));
    //std::string example = "bug";
    QString qmeaning = QString::fromStdString(meaning);
    QString qexample = QString::fromStdString(example);

    ui->meaningText->setText(qmeaning);
    ui->historyLabel->setText(QString::fromStdString(hist->getAllWordString()));
    ui->difficultText->setText(QString::fromStdString(diff));
    if(qexample.length()==0) {
        ui->exampleAllText->setText("没有例句");
    } else {
        ui->exampleAllText->setText(qexample);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("词库位置"));
    fileDialog->setDirectory(".");
    if(fileDialog->exec() == QDialog::Accepted) {
        QString path = fileDialog->selectedFiles()[0];
        ui->dictPath->setText(path);
        QMessageBox::information(NULL, tr("Path"), tr("你选择了：") + path);
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("你没有选择任何文件"));
    }
}

void MainWindow::on_loadButton_clicked()
{
    QString filePath = ui->dictPath->text();
    QString loadedPath = ui->loadedDict->text();
    bool isLoaded = dict->importDict(filePath.toStdString());

    if(isLoaded)
    {
        ui->dictPath->setText("");
        ui->loadedDict->setText(loadedPath + '\n' + filePath);
        QMessageBox::information(NULL, tr("加载成功"), tr("词库加载成功！"));
    }
    else
    {
        QMessageBox::information(NULL, tr("加载失败"), tr("词库加载失败！"));
    }
}

void MainWindow::on_addExampleButton_clicked()
{
    QString word = ui->wordText->toPlainText();
    QString example = ui->exampleText->toPlainText();
    QString translation = ui->translationText->toPlainText();
    if(word.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入单词！"));
        return;
    }
    if(example.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入例句！"));
        return;
    }
    if(translation.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入翻译！"));
        return;
    }
    bool isadded = dict->addExample(word.toStdString(), example.toStdString(), translation.toStdString());
    if(isadded) {
        ui->addexampleinfo->setText(tr("添加例句成功！"));
    }
    else {
        ui->addexampleinfo->setText(tr("添加例句失败！词库里没有该单词，请先加入单词！"));
    }
}

void MainWindow::on_addWordButton_clicked()
{
    QString word = ui->addWordText->toPlainText();
    QString meaning = ui->addMeaningText->toPlainText();
    QString difficult = ui->addDifficultText->toPlainText();
    if(word.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入单词！"));
        return;
    }
    if(meaning.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入释义！"));
        return;
    }
    if(difficult.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入难度"));
        return;
    }
    bool isadded = dict->addWord(word.toStdString(), meaning.toStdString(), difficult.toInt());
    if(isadded) {
        ui->add_modifyInfo->setText(tr("添加单词成功！"));
    }
    else {
        ui->add_modifyInfo->setText(tr("添加单词失败！词库里已有此单词！"));
    }
}



void MainWindow::on_modifyWordButton_clicked()
{
    QString word = ui->addWordText->toPlainText();
    QString meaning = ui->addMeaningText->toPlainText();
    QString difficult = ui->addDifficultText->toPlainText();
    if(word.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入单词!"));
        return;
    }
    if(meaning.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入释义!"));
        return;
    }
    if(difficult.length()==0) {
        QMessageBox::information(NULL, tr("错误"), tr("请输入难度(1-5)!"));
        return;
    }
    bool ismodified = dict->modifyWord(word.toStdString(), meaning.toStdString(), difficult.toInt());
    if(ismodified) {
        ui->add_modifyInfo->setText(tr("修改单词成功！"));
    }
    else {
        ui->add_modifyInfo->setText(tr("修改单词失败！词库里已有此单词！"));
    }
}



void MainWindow::on_deleteButton_clicked()
{
    int index = ui->indexLineEdit->text().toInt();
    bool isdeleted = hist->deleteWord(index);
    if(isdeleted) {
        ui->historyLabel->setText(QString::fromStdString(hist->getAllWordString()));
        ui->historyInfo->setText("删除记录成功！");
    }
    else {
        ui->historyInfo->setText("删除记录失败！请输入正确序号！");
    }
}

void MainWindow::on_deleteAllButton_clicked()
{
    bool isdeleted = hist->deleteAllWord();
    if(isdeleted) {
        ui->historyLabel->setText(QString::fromStdString(hist->getAllWordString()));
        ui->historyInfo->setText("删除所有记录成功！");
    }
    else {
        ui->historyInfo->setText("删除所有记录失败！原因未知！");
    }
}

int now_pos = 0;
//又是全局变量，怎么办
void MainWindow::on_startButton_clicked()
{
    if(dict->getDictSize() == 0) {
        QMessageBox::information(NULL, "错误", "请先加载词典！");
        return;
    }
    now_pos = 0;
    ui->reciteInfoLabel->setText("");
    recitelist->deleteAllWord();
    QString word_num = ui->wordNumLabel->text();
    int num = word_num.toInt();
    if(num <= 0 || num > dict->getDictSize()) {
        QMessageBox::information(NULL, "错误", "请输入正确的背诵条数！");
        return;
    }
    Recite *recite = new Recite(dict, num);
    if (recite == NULL) std::cout << "boom!\n";
    const std::vector<Word> &recite_list_vector = recite->makeReciteList();
    for(unsigned i = 0; i < recite_list_vector.size(); ++ i) {
        recitelist->addWord(recite_list_vector.at(i));
    }
    ui->wordLabel->setText(QString::fromStdString(recitelist->getWord(0).getWord()));
    ui->meaningLabel->setText(QString::fromStdString(recitelist->getWord(0).getMeaning()));
    ui->exampleLabel->setText(QString::fromStdString(recitelist->getWord(0).getAllExample()));
}

void MainWindow::on_prevButton_clicked()
{
    if(now_pos-1 >= 0) {
        ui->wordLabel->setText(QString::fromStdString(recitelist->getWord(now_pos-1).getWord()));
        ui->meaningLabel->setText(QString::fromStdString(recitelist->getWord(now_pos-1).getMeaning()));
        ui->exampleLabel->setText(QString::fromStdString(recitelist->getWord(now_pos-1).getAllExample()));
        now_pos --;
    }
    else {
        QMessageBox::information(NULL, "错误", "已经是第一个单词了!");
    }

}

void MainWindow::on_nextButton_clicked()
{
    if(now_pos+1 < recitelist->getHistorySize()) {
        ui->wordLabel->setText(QString::fromStdString(recitelist->getWord(now_pos+1).getWord()));
        ui->meaningLabel->setText(QString::fromStdString(recitelist->getWord(now_pos+1).getMeaning()));
        ui->exampleLabel->setText(QString::fromStdString(recitelist->getWord(now_pos+1).getAllExample()));
        now_pos ++;
    }
    else {
        QMessageBox::information(NULL, "错误", "已经是最后一个单词了!");
        ui->reciteInfoLabel->setText("您已背诵完成！");
    }

}

void MainWindow::on_addToListButton_clicked()
{
    Word word_in_list = recitelist->getWord((now_pos));
    dict->setDegree(word_in_list.getWord(), 5);
    wordlist->addWordWithoutDuplicate(word_in_list);
    ui->myWordLabel->setText(QString::fromStdString(wordlist->getAllWordString()));
}

void MainWindow::on_deleteMyWord_clicked()
{
    int index = ui->indexMyWord->text().toInt();
    dict->setDegree(hist->getWord(index).getWord(), 1);
    bool isdeleted = wordlist->deleteWord(index);
    if(isdeleted) {
        ui->myWordLabel->setText(QString::fromStdString(wordlist->getAllWordString()));
        ui->wordListInfo->setText("删除生词成功！");

    }
    else {
        ui->wordListInfo->setText("删除生词失败！请输入正确序号！");
    }
}

void MainWindow::on_deleteAllMyWord_clicked()
{
    for(unsigned i = 0; i != hist->getHistorySize(); i ++) {
        dict->setDegree(hist->getWord(i).getWord(), 1);
    }
    bool isdeleted = wordlist->deleteAllWord();
    if(isdeleted) {
        ui->myWordLabel->setText(QString::fromStdString(wordlist->getAllWordString()));
        ui->wordListInfo->setText("删除所有生词成功！");
    }
    else {
        ui->wordListInfo->setText("删除所有生词失败！未知原因！");
    }
}

void MainWindow::on_saveInfoButton_clicked()
{
    std::string userpath = username + "_";
    bool is_dict_exported = dict->exportDict(userpath+"dictionary.txt");
    dict->exportExample(userpath+"example.txt");
    wordlist->exportHistory(userpath+"wordlist.txt");
    hist->exportHistory(userpath+"history.txt");
    if(is_dict_exported) {
        QMessageBox::information(NULL, "完成", "保存完成！");
    }
    else {
        QMessageBox::information(NULL, "失败", "文件保存失败！");
    }
}

void MainWindow::on_loadInfoButton_clicked()
{
    std::string userpath = username + "_";
    bool is_dict_loaded = dict->importDict(userpath+"dictionary.txt");
    dict->importExample(userpath+"example.txt");
    wordlist->importHistory(userpath+"wordlist.txt");
    hist->importHistory(userpath+"history.txt");
    if(is_dict_loaded) {
        QMessageBox::information(NULL, "完成", "导入完成！");
        ui->loadedDict->setText("用户词典");
    }
    else {
        QMessageBox::information(NULL, "失败", "用户信息不存在！");
    }
    ui->myWordLabel->setText(QString::fromStdString(wordlist->getAllWordString()));
    ui->historyLabel->setText(QString::fromStdString(hist->getAllWordString()));
}

void MainWindow::on_translateButton_clicked()
{
    if(dict->getDictSize() == 0) {
        QMessageBox::information(NULL, "错误", "请先加载词库！");
        return;
    }
    Translation translator(dict);
    std::string raw = ui->sourceTextEdit->toPlainText().toStdString();
    translator.setRawString(raw);
    std::string out = translator.getOutString();
    ui->translationLabel->setText(QString::fromStdString(out));
}

std::vector<Test *> testlist;
//会不会内存泄露！！！
int num_of_tests = 0;
int now_test = 0;
void MainWindow::on_startTestButton_clicked()
{
    for (unsigned i = 0; i != testlist.size(); ++ i) {
        delete testlist.at(i);
    }
    if(dict->getDictSize() == 0) {
        QMessageBox::information(NULL, "错误", "请先加载词库!");
        return;
    }
    if(ui->testETCNumText->text()==0 || ui->testCTENumText->text()==0 || ui->testSPENumText->text()==0) {
        QMessageBox::information(NULL, "错误", "请输入正确题目数量!");
        return;
    }

    int ETOC = ui->testETCNumText->text().toInt();
    int CTOE = ui->testCTENumText->text().toInt();
    int SPEL = ui->testSPENumText->text().toInt();
    num_of_tests = ETOC + CTOE + SPEL;
    if(num_of_tests <= 0 && num_of_tests >= dict->getDictSize()) {
        QMessageBox::information(NULL, "错误", "请输入正确题数!");
        return;
    }

    now_test = 0;
    TestList *tsl = new TestList(ETOC, CTOE, SPEL, dict);
    tsl->makeTestList();
    testlist = tsl->getTestList();
    ui->testLabel->setText(QString::fromStdString(testlist.at(now_test)->getTest()));
}

void MainWindow::on_testConfirmButton_clicked()
{
    std::string user_ans = ui->testUserAnsEdit->text().toStdString();
    if(user_ans.length() == 0) {
        QMessageBox::information(NULL, "错误", "请输入答案!");
        return;
    }
    if(testlist.at(now_test)->isCorrect(user_ans)) {
        ui->testInfoLabel->setText("恭喜您！回答正确！");
    }
    else {
        ui->testInfoLabel->setText("回答错误！" + QString::fromStdString(testlist.at(now_test)->getTestAns()));
    }
    if(now_test + 1 < num_of_tests) {
        now_test ++;
        ui->testUserAnsEdit->setText("");
        ui->testLabel->setText(QString::fromStdString(testlist.at(now_test)->getTest()));
    }
    if(now_test == num_of_tests - 1) {
        QMessageBox::information(NULL, "恭喜", "您已完成测试!");
    }
}

void MainWindow::on_testNextButton_clicked()
{
    if(now_test + 1 < num_of_tests) {
        now_test ++;
        ui->testInfoLabel->setText("");
        ui->testUserAnsEdit->setText("");
        ui->testLabel->setText(QString::fromStdString(testlist.at(now_test)->getTest()));
    }
    else {
        QMessageBox::information(NULL, "错误", "已经到最后一题");
    }
}

void MainWindow::on_testPrevButton_clicked()
{
    if(now_test - 1 >= 0) {
        now_test --;
        ui->testInfoLabel->setText("");
        ui->testUserAnsEdit->setText("");
        ui->testLabel->setText(QString::fromStdString(testlist.at(now_test)->getTest()));
    }
    else {
        QMessageBox::information(NULL, "错误", "已经到第一题");
    }
}

void MainWindow::on_addToListButtonInSearch_clicked()
{
    if(dict->isExisted(ui->lineEdit->text().toStdString())) {
        Word search_word = dict->getSearchWord(ui->lineEdit->text().toStdString());
        dict->setDegree(ui->lineEdit->text().toStdString(), 5);
        wordlist->addWordWithoutDuplicate(dict->getSearchWord(ui->lineEdit->text().toStdString()));
        ui->myWordLabel->setText(QString::fromStdString(wordlist->getAllWordString()));
    }
}


void MainWindow::on_loadExampleButton_clicked()
{
    QString filePath = ui->dictPath->text();
    QString loadedPath = ui->loadedDict->text();
    bool isLoaded = dict->importExample(filePath.toStdString());

    if(isLoaded)
    {
        ui->dictPath->setText("");
        ui->loadedDict->setText(loadedPath + '\n' + filePath);
        QMessageBox::information(NULL, tr("加载成功"), tr("例句库加载成功！"));
    }
    else
    {
        QMessageBox::information(NULL, tr("加载失败"), tr("例句库加载失败！"));
    }
}

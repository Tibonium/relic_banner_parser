#ifndef RELIC_BANNER_PARSER_H
#define RELIC_BANNER_PARSER_H

#include <QWidget>
#include <QFileDialog>
#include <QSettings>
#include <QCloseEvent>

#include "html_source_parser.h"

namespace Ui {
class relic_banner_parser;
}

class relic_banner_parser : public QWidget
{
    Q_OBJECT

public:
    explicit relic_banner_parser(QWidget *parent = 0);
    ~relic_banner_parser();

    void closeEvent(QCloseEvent *e) ;

private slots:
    void on_load_html_file_clicked();

    void on_extract_button_clicked();

private:
    Ui::relic_banner_parser *ui;

    QSettings _settings ;
    void load_settings() ;
    void save_settings() ;
};

#endif // RELIC_BANNER_PARSER_H

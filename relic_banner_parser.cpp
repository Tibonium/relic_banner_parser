#include "relic_banner_parser.h"
#include "ui_relic_banner_parser.h"

relic_banner_parser::relic_banner_parser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::relic_banner_parser),
    _settings("Tibonium Inc.", "relic_banner_parser")
{
    ui->setupUi(this) ;
    load_settings() ;
}

relic_banner_parser::~relic_banner_parser()
{
    delete ui;
}

void relic_banner_parser::closeEvent(QCloseEvent *e)
{
    save_settings() ;
    e->accept() ;
}

void relic_banner_parser::load_settings()
{
    if( _settings.contains("html_file") ) {
        ui->html_filename->setText( _settings.value("html_file").toString() );
    }
    if( _settings.contains("position") ) {
        move( _settings.value("position").toPoint() ) ;
    }
    if( _settings.contains("size") ) {
        resize( _settings.value("size").toSize() ) ;
    }
}

void relic_banner_parser::save_settings()
{
    _settings.setValue("position", pos()) ;
    _settings.setValue("size", size()) ;
    if( !ui->html_filename->text().isEmpty() ) {
        _settings.setValue("html_file", ui->html_filename->text());
    }
}

void relic_banner_parser::on_load_html_file_clicked()
{
    QFileDialog msg ;
    if( msg.exec() ) {
        QStringList files = msg.selectedFiles() ;
        if( files.size() > 0 ) {
            ui->html_filename->setText( files[0] ) ;
        }
    }
}

void relic_banner_parser::on_extract_button_clicked()
{
    QString filename = ui->html_filename->text() ;
    if( !filename.isEmpty() ) {
        ui->comment_display->clear() ;
        html_source_parser hsp( filename.toLatin1().data() ) ;
        html_source_parser::list_type* data = hsp.data() ;
        html_source_parser::list_type::iterator It = data->begin() ;
        html_source_parser::list_type::iterator It_end = data->end() ;
        QString comments ;
        while( It != It_end ) {
            comments += It->c_str() ;
            It++ ;
        }
        ui->comment_display->setText( comments ) ;
    }
}

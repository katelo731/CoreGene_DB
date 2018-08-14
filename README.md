## Workflow :

genomes -> MMseqs2 on Linux -(transform)-> BLASTp output -> Separate Paralog & Ortholog -(now focus on ortholog)
 -> delete row which evalue > 1e-5 -> set K as a constant to represent the threshold -> Cytoscape cluster graphs
 -> decide # clusters -> ... -> store in DB -> GUI webpage oriented to find core gene

## Webpage Spec :

### input :

e-value, scores, % overlapping ...

DNA seq needed to be compared with 

### output :

core gene

## Ref :

- [SQLite vs MySQL vs PostgreSQL：关系型数据库比较](http://www.infoq.com/cn/news/2014/04/sqlite-mysql-postgresql)

- [簡單的 MySQL 使用教學](https://jerrynest.io/mysql-tutorial/)

- [MySQL 超新手入門](http://www.codedata.com.tw/category/database/5)

- [How to import data from text file to mysql database](https://stackoverflow.com/questions/13579810/how-to-import-data-from-text-file-to-mysql-database)

- [High Scaling Websites Structure Learning Notes 大型網站架構學習筆記](https://www.kancloud.cn/kancloud/high-scaling-structure-notes/50233)

- [Copy your test site to a live site (GUI)](https://www.drupal.org/docs/7/upgrade-to-drupal-7/copy-your-test-site-to-a-live-site-gui)

- [XAMPP 網頁伺服器架站工具設定與使用教學](https://www.pcsetting.com/devtools/54?page=0%2C0) (done)

- [Drupal 8 好用的 CMS 架站軟體安裝設定與使用教學](https://www.pcsetting.com/devtools/60?page=0%2C0) (done)

- [新手必看 Drupal Module 整理列表](https://bonze.tw/drupal_module_list/#base)

- [如何利用phpMyAdmin建立MySQL資料庫與設計？](https://sofree.cc/phpmyadmin-mysql/)

- []()



-- 创建一个名称为medicine的数据库
create database medicine;

-- 删除数据库medicine
-- drop database medicine;

-- 使用数据库medicine
use medicine;

-- 创建表（用户表 user）
create table user(
	account varchar(255) primary key, 
	password varchar(255), 
	name varchar(255), 
	classification varchar(255)
);

-- 删除表
-- drop table user;

-- 插入数据
insert into user values('beijing', 'bj', '北京', '管理员');
insert into user values('test', 'haha', 'Mike', '管理员');
insert into user values('Kevin', '123456', 'Tom', '售药员');
insert into user values('Lily', 'itcast', 'Lily', '售药员');
insert into user values('abc', '250250', 'Irina', '管理员');
insert into user values('123456', '123456', '令狐冲', '医生');
insert into user values('hehe', 'hehe', '云中鹤', '医生');
insert into user values('kfc', 'kfc', 'kfc', '医生');
insert into user values('gz', 'gz', '广州', '管理员');
insert into user values('sh', 'sh', '上海', '管理员');

-- 创建表（药品表 medicine）
create table medicine(
	id varchar(100) primary key, 
	name varchar(255),
	classification varchar(100),
	produceDate datetime,
	producePlace varchar(100),
	discription varchar(255),
	produceCompany varchar(255),
	quelityAssurance int,
	unitPrice int,
	number int
);

-- 插入数据
insert into medicine values('A1', '感冒胶囊', '感冒类', '2015-01-04','长沙','西药','三九集团',24,50,100);
insert into medicine values('A2', '银翘片', '感冒类', '2014-02-05','贵州','中药','贵州百灵',36,30,80);
insert into medicine values('A3', '感冒通', '感冒类', '2015-02-15','石家庄','中药','石药集团',36,25,200);
insert into medicine values('A4', '感冒冲剂', '感冒类', '2010-11-11','哈尔滨','中药','哈药六厂',24,20,0);
insert into medicine values('B1', '三黄片', '清热解毒类', '2015-12-11','沈阳','中药','沈阳第一制药厂',24,20,250);
insert into medicine values('B2', '牛黄解毒片', '清热解毒类', '2015-07-10','北京','中药','同仁堂',24,15,200);
insert into medicine values('B3', '清火栀麦片', '清热解毒类', '2015-06-10','上海','中药','长海长乐药厂',24,20,98);
insert into medicine values('C1', '青霉素', '抗生素类', '2015-08-18','石家庄','西药','石药集团',12,80,222);
insert into medicine values('C2', '红霉素', '抗生素类', '2015-09-20','桂林','西药','桂林三金药业',12,60,300);
insert into medicine values('C3', '头孢拉定胶囊', '抗生素类', '2015-10-27','烟台','西药','荣昌制药',12,100,180);


-- 删除medicine表
-- drop table medicine;

-- 创建表（药品出售情况表 saleTable）
create table saleTable(
	id varchar(100) primary key,
	name varchar(255),
	number int,
	price int
);

-- 插入数据
insert into saleTable values('B3','清火栀麦片',2,40);

-- 删除saleTable 表
-- drop table saleTable;


































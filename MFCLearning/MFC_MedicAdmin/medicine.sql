-- ����һ������Ϊmedicine�����ݿ�
create database medicine;

-- ɾ�����ݿ�medicine
-- drop database medicine;

-- ʹ�����ݿ�medicine
use medicine;

-- �������û��� user��
create table user(
	account varchar(255) primary key, 
	password varchar(255), 
	name varchar(255), 
	classification varchar(255)
);

-- ɾ����
-- drop table user;

-- ��������
insert into user values('beijing', 'bj', '����', '����Ա');
insert into user values('test', 'haha', 'Mike', '����Ա');
insert into user values('Kevin', '123456', 'Tom', '��ҩԱ');
insert into user values('Lily', 'itcast', 'Lily', '��ҩԱ');
insert into user values('abc', '250250', 'Irina', '����Ա');
insert into user values('123456', '123456', '�����', 'ҽ��');
insert into user values('hehe', 'hehe', '���к�', 'ҽ��');
insert into user values('kfc', 'kfc', 'kfc', 'ҽ��');
insert into user values('gz', 'gz', '����', '����Ա');
insert into user values('sh', 'sh', '�Ϻ�', '����Ա');

-- ������ҩƷ�� medicine��
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

-- ��������
insert into medicine values('A1', '��ð����', '��ð��', '2015-01-04','��ɳ','��ҩ','���ż���',24,50,100);
insert into medicine values('A2', '����Ƭ', '��ð��', '2014-02-05','����','��ҩ','���ݰ���',36,30,80);
insert into medicine values('A3', '��ðͨ', '��ð��', '2015-02-15','ʯ��ׯ','��ҩ','ʯҩ����',36,25,200);
insert into medicine values('A4', '��ð���', '��ð��', '2010-11-11','������','��ҩ','��ҩ����',24,20,0);
insert into medicine values('B1', '����Ƭ', '���Ƚⶾ��', '2015-12-11','����','��ҩ','������һ��ҩ��',24,20,250);
insert into medicine values('B2', 'ţ�ƽⶾƬ', '���Ƚⶾ��', '2015-07-10','����','��ҩ','ͬ����',24,15,200);
insert into medicine values('B3', '�������Ƭ', '���Ƚⶾ��', '2015-06-10','�Ϻ�','��ҩ','��������ҩ��',24,20,98);
insert into medicine values('C1', '��ù��', '��������', '2015-08-18','ʯ��ׯ','��ҩ','ʯҩ����',12,80,222);
insert into medicine values('C2', '��ù��', '��������', '2015-09-20','����','��ҩ','��������ҩҵ',12,60,300);
insert into medicine values('C3', 'ͷ����������', '��������', '2015-10-27','��̨','��ҩ','�ٲ���ҩ',12,100,180);


-- ɾ��medicine��
-- drop table medicine;

-- ������ҩƷ��������� saleTable��
create table saleTable(
	id varchar(100) primary key,
	name varchar(255),
	number int,
	price int
);

-- ��������
insert into saleTable values('B3','�������Ƭ',2,40);

-- ɾ��saleTable ��
-- drop table saleTable;


































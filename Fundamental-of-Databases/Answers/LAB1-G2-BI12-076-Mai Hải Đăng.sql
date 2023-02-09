DROP DATABASE IF EXISTS `Company`;
CREATE DATABASE `Company`;
USE `Company`;
SET GLOBAL FOREIGN_KEY_CHECKS=0;

CREATE TABLE DEPARTMENT(
	`Dname` varchar(50),
	`Dnumber` int,
    `Mgr_ssn` int,
    `Mgr_start_date` date,
    PRIMARY KEY (`Dnumber`)  
);

CREATE TABLE SPOUSE( -- The reference table for the ssn of spouses
	Spouse_Ssn int,
    PRIMARY KEY(Spouse_Ssn)
);

CREATE TABLE EMPLOYEE (
	`Fname` varchar(50),
    `Minit` varchar(50),
    `Lname` varchar(50),
    `Bdate` date,
    `Ssn` int,
    `Address` varchar(50),
    `Sex` varchar(1),
    `Salary` int,
    `Super_ssn` int,
    `Dno` int,
    Partner_ssn int, -- spouse ssn
    PRIMARY KEY(`Ssn`),
    CONSTRAINT FOREIGN KEY(`Dno`) REFERENCES DEPARTMENT(`Dnumber`),
	CONSTRAINT FOREIGN KEY(`Super_ssn`) REFERENCES EMPLOYEE(`Ssn`),
    CONSTRAINT FOREIGN KEY(Partner_ssn) REFERENCES SPOUSE(Spouse_Ssn) -- references to the spouse_ssn table
);

CREATE TABLE DEPT_LOCATIONS (
	Dnumber INT,
    Dlocation varchar(50),
    PRIMARY KEY(Dnumber, Dlocation),
    CONSTRAINT FOREIGN KEY(Dnumber) REFERENCES DEPARTMENT(Dnumber) 
);

CREATE TABLE PROJECT (
	Pname varchar(50),
    Pnumber INT,
    Plocation varchar(50),
    Dnum INT,
    PRIMARY KEY(Pnumber),
    CONSTRAINT FOREIGN KEY(Dnum) REFERENCES DEPARTMENT(Dnumber) ON UPDATE CASCADE
);

CREATE TABLE WORKS_ON (
	Essn INT,
    Pno INT,
    Hours INT,
    PRIMARY KEY(Essn, Pno),
    CONSTRAINT FOREIGN KEY(Essn) REFERENCES EMPLOYEE(Ssn) ON UPDATE CASCADE,
    CONSTRAINT FOREIGN KEY(Pno) REFERENCES PROJECT(Pnumber) ON UPDATE CASCADE
);

CREATE TABLE DEPENDENT (
	Essn INT,
    Dependent_name varchar(50),
    Sex varchar(1),
    Bdate date,
    Relationship varchar(50),
    PRIMARY KEY(Essn, Dependent_name),
    CONSTRAINT FOREIGN KEY(Essn) REFERENCES EMPLOYEE(Ssn) ON UPDATE CASCADE
);

-- 4. Insert sample rows
-- INSERT INTO SPOUSE VALUE(11223344);
-- INSERT INTO DEPARTMENT VALUES('Research',5,333445555,'1988-05-22');
-- INSERT INTO DEPT_LOCATIONS VALUES(5,'Houston');
-- INSERT INTO EMPLOYEE VALUES ('John','B','Smith','1956-01-09',123456789,'731 Fondren,Houston,TX','M',30000,123456789,5,NULL);
-- INSERT INTO EMPLOYEE VALUES ('James','C','Gun','1996-11-29',1234567,'723, Camrump, Texis,TW','M',300000,1234567,5,11223344);
-- INSERT INTO PROJECT VALUES ('ProductX',1,'Bellaire',5);
-- INSERT INTO WORKS_ON VALUES (123456789,1,32.5);
-- INSERT INTO DEPENDENT VALUES (123456789,'Alice','F','1986-04-05','DAUGHTER');

-- 5. deleting the spouse table
-- ALTER TABLE EMPLOYEE DROP CONSTRAINT employee_ibfk_3;
-- DROP TABLE SPOUSE;
USE northwind;
SELECT * FROM northwind.products; 
SELECT 
	id,
    product_name,
    discontinued
FROM products
WHERE discontinued = 1;

SELECT *
FROM products 
ORDER BY standard_cost ASC;

SELECT 
	id, 
    product_name, 
    list_price 
FROM products
WHERE list_price BETWEEN 15 AND 25;

SELECT
	id,
    CONCAT(first_name, " ", last_name) AS full_name
FROM employees;

SELECT
	first_name
FROM employees 
WHERE first_name 
LIKE 'A%';

SELECT @rownum := @rownum + 1 AS 'number', employees.city
FROM   (SELECT DISTINCT city
        FROM employees) employees
       JOIN (SELECT @rownum := 0) r ;

SELECT 
	DISTINCT ship_name
FROM orders;

SELECT 
	MIN(list_price) AS SmallestPrice,
    MAX(list_price) AS HighestPrice
FROM products;

SELECT * FROM products WHERE discontinued = 0;

SELECT
	STDDEV(list_price) AS "Standard Deviation",
    avg(list_price) AS "Average"
FROM products;

SELECT 
	product_name,
    list_price
FROM products WHERE list_price > ANY(SELECT avg(list_price) FROM products);

INSERT INTO suppliers (company, last_name, first_name, city, country_region) VALUES ('Habeco','Nguyễn', 'Hồng Linh','Hanoi','Vietnam');
INSERT INTO products (product_code, supplier_ids, list_price, discontinued, category) VALUES ('TBTrucBach','Habeco','22',0,'Beverages');
UPDATE products SET standard_cost = 18 WHERE product_code = 'TBTrucBach';

DELETE FROM suppliers WHERE company = 'Habeco';
DELETE FROM products WHERE product_code = 'TBTrucBach';
 



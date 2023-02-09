USE northwind;
-- 1 
SELECT order_date FROM orders WHERE order_date > '2006-03-24';
-- 2
SELECT 
	product_code,
    quantity,
	order_id, 
    unit_price,
    unit_price*quantity*(1-discount) AS value
FROM order_details JOIN products ON order_details.product_id = products.id WHERE order_id =31;

-- 3 
SELECT 
	orders.id AS id,
    order_date,
    company,
    unit_price*quantity*(1-discount) AS value
FROM orders JOIN customers ON orders.customer_id = customers.id JOIN order_details ON order_details.order_id = orders.id 
WHERE order_date > '2006-03-24' group by order_id;

-- 4
SELECT 
	orders.id AS id,
    order_date,
    company,
    sum(unit_price*quantity*(1-discount)) AS sub_total
FROM orders JOIN customers ON orders.customer_id = customers.id JOIN order_details ON order_details.order_id = orders.id 
WHERE order_date > '2006-03-24' group by order_id;


-- 5
SELECT 
	orders.id AS id,
    order_date,
    company,
    sum(unit_price*quantity*(1-discount)) AS sub_total
FROM orders JOIN customers ON orders.customer_id = customers.id JOIN order_details ON order_details.order_id = orders.id 
WHERE order_date > '2006-03-24' group by order_id;

-- 6
select concat(first_name," ", last_name) as full_name, sum(unit_price*quantity*(1-discount)) as sale from orders 
join employees on orders.employee_id = employees.id
join order_details on order_details.order_id = orders.id
group by employees.id having sale>1000
order by sale DESC;
-- 7
select company,concat(first_name," ", last_name) as full_name, email_address, 'C' as type from customers
union all
select company,concat(first_name," ", last_name) as full_name, email_address, 'S' as type from suppliers;

-- 8
select distinct category from products order by category ;

-- 9
select min(standard_cost) as minimum, max(standard_cost) as maximum, avg(standard_cost) as average, stddev(standard_cost) as 'standard deviation',variance(standard_cost) as 'variance' from products;

-- 10
select category, avg(list_price) as average from products group by category;

-- 11
set @n = 10;
call Show_top_n(@n);

-- 12
select category, avg(list_price) as average from products group by category order by avg(list_price) ASC limit 1;

-- 13 
select purchase_orders.id, concat(h1.first_name," ", h2.last_name) as person_creating, concat(h2.first_name, " ", h2.last_name) as person_approving from purchase_orders
join employees h1 on purchase_orders.created_by = h1.id
join employees h2 on purchase_orders.approved_by = h2.id
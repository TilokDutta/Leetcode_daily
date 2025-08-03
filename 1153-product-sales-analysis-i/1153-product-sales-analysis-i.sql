# Write your MySQL query statement below
select product.product_name, Sales.year, Sales.price from Sales join Product on Sales.product_id = Product.product_id;
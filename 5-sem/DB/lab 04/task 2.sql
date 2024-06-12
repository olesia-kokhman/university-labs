SELECT cname, city, rating
FROM public."Customers"
WHERE
city = 'New York' OR city = 'Los Angeles'
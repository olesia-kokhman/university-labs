SELECT cname, city, rating
FROM public."Customers"
WHERE NOT city = 'New York' AND rating > 2
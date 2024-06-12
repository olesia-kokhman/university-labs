SELECT public."Sales".id, public."Sales".name AS SaleName, 
LOWER(public."Projects".name) AS ProjectName, public."Projects".budget
FROM public."Sales"
FULL JOIN public."Projects" ON public."Sales".id = public."Projects".sale_id
WHERE public."Sales".id = 5 AND budget = 10000 
ORDER BY ProjectName ASC



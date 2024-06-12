SELECT public."Projects".id, UPPER(public."Projects".name), public."Projects".budget, 
SUM(public."Payments".amount)
FROM public."Projects"
LEFT JOIN public."Payments" ON public."Projects".id = public."Payments".project_id
GROUP BY public."Projects".id, public."Projects".name, public."Projects".budget
HAVING NOT name='SEO Improvement' AND budget > 5000 LIMIT



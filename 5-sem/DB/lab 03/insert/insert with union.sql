INSERT INTO public."Irrelevant_Skills"(id, name)
SELECT id, name
FROM public."Skills"
WHERE id = 20
UNION
SELECT id, name
FROM public."Skills"
WHERE id = 30;
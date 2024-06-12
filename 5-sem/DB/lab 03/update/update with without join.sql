UPDATE public."Developers_Skills"
SET skills_id = public."Skills".id
FROM public."Skills"
WHERE public."Developers_Skills".skills_id = public."Skills".id;

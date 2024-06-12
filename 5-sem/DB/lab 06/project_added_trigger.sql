CREATE TRIGGER project_added_trigger
BEFORE INSERT ON public."Projects"
FOR EACH ROW
	EXECUTE FUNCTION execute_project_adding2()
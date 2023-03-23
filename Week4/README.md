Зад 1. (Текстов файл): 
	Вход: CSV с дневните температури за послдните X години. Колона 1=dd/mm/yyyy, Колона 2=температура
	Изход: CSV със следните 5 колони: година(yyyy), мин. темп за годината, макс. темп, средна темп, брой дни в които имаме измерване

Зад 2. (Binary файл):

	Имаме бинарен файл с резултати на студентите, по следната схема: 1 entry = Course ID: char[6] (при CS301, PHY553), Strudent ID char[10], Student Note: int

	Искаме следните функции:
	 - IntVector getStrudentNodes(studentId)
	 - IntVector getCourseNotest(courseId)
	 - double getStudentAverage(studentId)
	 - double getCourseAverage(courseId)

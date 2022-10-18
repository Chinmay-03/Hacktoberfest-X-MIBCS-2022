pragma solidity ^<*version*>;

// Build the Contract
<*keyword*> MarksManagmtSys
{
	//structure for student details
	struct Student
	{
		int ID;
		string name;
		int marks;
	}

	<*datatype*> owner;
	int public stdCount = 0;
	mapping(int => Student) public stdRecords;

	modifier onlyOwner
	{
		require(owner == msg.sender);
		_;
	}
	constructor()
	{
		owner=msg.sender;
	}

	// Create a function to add the new records
	function addNewRecords(int _ID,
						string memory _name,
						int _marks) public onlyOwner
	{
		// Increase the count by 1
		stdCount = ;

		// Fetch the student details with the help of stdCount
		stdRecords[stdCount] = Student(_ID, _name, _marks);
	}

	// Create a function to add bonus marks
	function bonusMarks(int _bonus) public onlyOwner
	{
		stdRecords[stdCount].marks =
					stdRecords[stdCount].marks + _bonus;
	}
}

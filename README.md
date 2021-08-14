Time spent on design, implementation, and tests: **5.5 hours**.
The placement of the definitions inside the header files is intentional, so to aid the browsing among files.

**1.** Current employees are read out from a file. 

**2.** Settings are read out from a file (as was specified) at the time of creation of first instance of some class derived from the Account class. Afterwards, settings are stored as a static std::unordered_map, which maps a wage category name (std::string) to a wage (double). 
While it is a common knowledge to not store money values in floating point types, yet this good practice was omitted for simplicity here. Also, the use of std::string as a label for a wage category may need a reconsideration.

**3.** Both Staff.h and Settings.h read from text files, so both inherit from a DataFile class which factors out common file management issues.

**4.** File names are hardcoded as preprocessor macros.

**5.** The implementation of the Singleton is thread safe due to the fact that "such a variable is initialized the first time control passes through its declaration; such a variable is considered initialized upon the completion of its initialization" - and then - "if control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization".


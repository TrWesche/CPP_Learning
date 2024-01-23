Guidance:
- Be careful with Heap memory.  You can easily cause memory leaks when using a try/catch block since it will exit immediately without properly cleaning up after itself.
- If you throw an object that object must be copyable (i.e. you must have a public copy constructor implemented)
- Don't throw local pointers, the value will be out of scope in the catch block



Some Usages:
- Handling invalid operations (ex. Dividing by 0)
- Handling cast failures (i.e. trying to cast a basic type such as "Animal" to a derived type such as "Dog."  The animal will not have the information necessary to become a dog.)
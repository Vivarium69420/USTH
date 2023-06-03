package a2_bi12_076.studentman;
import a2_bi12_076.kengine.Doc;
import utils.AttrRef;
import utils.DomainConstraint;
import utils.NotPossibleException;
import utils.OptType;
import utils.DOpt;
import java.lang.Comparable;
import java.lang.String;



/**
 * @Overview 
 * 			StudentMan of a university captures and processes
 * 			data about an entity named Student and two specific types of
 * 			Student named UndergradStudent (undergraduate student)
 * 			and PostgradStudent (post-graduate student)
 * @attributes
 * 			id 			Integer 	int
 * 			name		String	
 * 			phoneNumber	String
 * 			address		String
 * @object
 * 			A typical Student is <i, n, p, a>, where i (id), n (name), p (phoneNumber), a (address)
 * @abstract_properties
 * 			mutable(id)=false /\ optional(id)=false /\ min(id)=1 /\ max(id)=10^9
 * 			mutable(name)=true /\ optional(name)=false /\ length(name)=50
 * 			mutable(phoneNumber)=true /\ optional(phoneNumber)=false /\ length(phoneNumber)=10
 * 			mutable(address)=true /\ optional(address)=false /\ length(address)=100
 * 
 * 			
 * @author BI12-076 Mai Hai Dang
 *
 */
public class Student implements Comparable<Student>, Document{

	private static final int MIN_STUDENT_ID = 1;
	private static final int MAX_STUDENT_ID = 1000000000;
	private static final int LENGTH_NAME = 50;
	private static final int LENGTH_PHONENUMBER = 10;
	private static final int LENGTH_ADDRESS = 100;
	
	@DomainConstraint(type = "Integer", mutable = false, optional = false, min = MIN_STUDENT_ID, max = MAX_STUDENT_ID)
	private int id;
	
	@DomainConstraint(type = "String", optional = false, length = LENGTH_NAME)
	private String name;
	
	@DomainConstraint(type = "String", optional = false, length = LENGTH_PHONENUMBER)
	private String phoneNumber;
	
	@DomainConstraint(type = "String", optional = false, length = LENGTH_ADDRESS)
	private String address;

	/**
   * Constructor
	 * @effect <pre>
	 * 			if id, name, phoneNumber, address are valid
	 * 				initialize this as Student:<id, name, phoneNumber, address?
	 * 			else
	 * 				throws NotPossibleException
	 * 			</pre>
	 */
	public Student(
			@AttrRef("id") int id,
			@AttrRef("name") String name,
			@AttrRef("phoneNumber") String phoneNumber,
			@AttrRef("address") String address) throws NotPossibleException{
	
		if (!validateId(id)) 
			throw new NotPossibleException("Student.init: Inivalid id: " + id);
		if (!validateName(name)) 
			throw new NotPossibleException("Student.init: Inivalid name: " + name);
		
		if (!validatePhoneNumber(phoneNumber)) 
			throw new NotPossibleException("Student.init: Inivalid phoneNumber: " + phoneNumber);
		
		if (!validateAddress(address)) 
			throw new NotPossibleException("Student.init: Inivalid address: " + address);
	
		// all are valid
		this.id = id;
		this.name = name;
		this.phoneNumber = phoneNumber;
		this.address = address;
	}
	// methods
	/**
	 * @effects return <tt>this.name</tt>
	 */
	@DOpt(type = OptType.Observer) @AttrRef("name")
	public String getName() {
		return name;
	}
	
	/**
	 * @effects <pre>
	 * 			if name is valid
	 * 				set this.name = name
	 * 			else
	 * 				throw NotPossibleException
	 */
	@DOpt(type = OptType.Mutator) @AttrRef("name")
	public boolean setName(String name) {
		if (validateName(name)) { 
			this.name = name;
			return true;
		}
		else 
			return false;
	}
	
	/**
	 * @effects return <tt>this.phoneNumber</tt>
	 */
	@DOpt(type = OptType.Observer) @AttrRef("phoneNumber")
	public String getPhoneNumber() {
		return phoneNumber;
	}

	/**
	 * @effects <pre>
	 * 			if phoneNumber is valid
	 * 				set this.phoneNumber = name
	 * 			else
	 * 				throw NotPossibleException
	 */
	@DOpt(type = OptType.Mutator) @AttrRef("phoneNumber")
	public boolean setPhoneNumber(String phoneNumber) {
		if (validatePhoneNumber(phoneNumber)){ 
			this.phoneNumber = phoneNumber;
			return true;
		}
		else 
			return false;
	}

	/**
	 * @effects return <tt>this.address</tt>
	 */
	@DOpt(type = OptType.Observer) @AttrRef("address")
	public String getAddress() {
		return address;
	}

	/**
	 * @effects <pre>
	 * 			if address is valid
	 * 				set this.address = address
	 * 			else
	 * 				throw NotPossibleException
	 */
	@DOpt(type = OptType.Mutator) @AttrRef("address")
	public boolean setAddress(String address) {
		if (validateAddress(address)){ 
			this.address = address;
			return true;
		}
		else 
			return false;
	}

	/**
	 * @effects return <tt>this.id</tt>
	 * @return
	 */
	@DOpt(type = OptType.Observer) @AttrRef("id")
	public int getId() {
		return id;
	}
	
	/**
	 * @effects <pre>
	 * 			if this satisfies rep invariant
	 * 				return true
	 * 			else
	 * 				return false
	 */
	public boolean repOK() {
		return validateId(id) && validateName(name) && validatePhoneNumber(phoneNumber) && validateAddress(address);
	}
	
  /**
   * @effects <pre>
   *            if o is null 
   *              throws NullPointerException 
   *            else if o is not a Student object
   *              throws ClassCastException
   *            else 
   *              returns this.name.compareTo(o.name)
   *          </pre>
   */
	@Override
	public int compareTo(Student o) throws NullPointerException, ClassCastException {
			if (o == null) 
				throw new NullPointerException("Student.compareById");
			else if (!(o instanceof Student))
				throw new ClassCastException("Student.compareById: Not a Student" + o);
			
			Student student = (Student) o;
			return this.name.compareTo(student.name);
	}
	/**
	 * @effects <pre>
	 *      return a simple HTML document generated from the state of the current object
	 *      </pre>
	 */
  public String toHtmlDoc(){
    return 
    "<html> <head><title>Student:" + id + "-" + name + "</title></head><body>" + id + name + phoneNumber + address + "</body></html>";
  }


	/**
	 * @effects <pre>
	 * 			return a string representation of this object
	 * 			</pre>
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("Student: <");
    	sb.append("Id: ").append(id).append(", ")
    	  .append("Name: ").append(name).append(", ")
    	  .append("Phone Number: ").append(phoneNumber).append(", ")
    	  .append("Address: ").append(address).append(">");
    	return sb.toString();
	}
	
	/**
	 * @effects <pre>
	 * 			if id is valid
	 * 				return true
	 * 			else
	 * 				return false 
	 * 			</pre>
	 */
	protected boolean validateId(int id) {
		if ((id < MIN_STUDENT_ID) || (id > MAX_STUDENT_ID)) 
			return false;
		return true;
	}
	
	/**
	 * @effects <pre>
	 * 			if name is valid
	 * 				return true
	 * 			else
	 * 				return false 
	 * 			</pre>
	 */
	private boolean validateName(String name) {
		if ((name == null) || (name.length() > LENGTH_NAME)) 
			return false;
		return true;
	}
	
	/**
	 * @effects <pre>
	 * 			if phoneNumber is valid
	 * 				return true
	 * 			else
	 * 				return false 
	 * 			</pre>
	 */
	private boolean validatePhoneNumber(String phoneNumber) {
		if ((phoneNumber == null) || (phoneNumber.length() > LENGTH_PHONENUMBER)) 
			return false;
		return true;
	}
	
	/**
	 * @effects <pre>
	 * 			if address is valid
	 * 				return true
	 * 			else
	 * 				return false 
	 * 			</pre>
	 */
	private boolean validateAddress(String address) {
		if ((address == null) || (address.length() > LENGTH_ADDRESS)) 
			return false;
		return true;
	}

  
}

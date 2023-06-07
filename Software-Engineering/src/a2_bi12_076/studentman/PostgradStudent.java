package a2_bi12_076.studentman;
import a2_bi12_076.kengine.Doc;
import utils.AttrRef;
import utils.DOpt;
import utils.DomainConstraint;
import utils.NotPossibleException;
import utils.OptType;

/**
 * @overview 
 * 			PostgradStudent is a sub-class of Student representing an student that is
 * 			in an postgraduate course
 * 
 * @attributes
 * 			gpa 	Float
 * 
 * @abstract_properties
 * 			P_Student /\
 * 			min(id)=10^8+1 /\ max(id)=10^9 /\
 * 			mutable(gpa)=true /\ optional(gpa)=false /\ min(gpa)=0.0 /\ max(gpa)=4.0
 * 
 * @object
 * 			A typical PostgradStudent is <i, n, p, a, g>, where i (id), n (name), p (phoneNumber), a (address), g (gpa)
 * 
 * @author BI12-076 Mai Hai Dang
 *
 */
public class PostgradStudent extends Student{

	private static final int MIN_POSTGRADSTUDENT_ID = 100000001;
	private static final int MAX_POSTGRADSTUDENT_ID = 1000000001;
	private static final float MIN_POSTGRADSTUDENT_GPA = (float) 0.0;
	private static final float MAX_POSTGRADSTUDENT_GPA = (float) 4.0;
	
	@DomainConstraint(type = "Float", optional = false, min = MIN_POSTGRADSTUDENT_GPA, max = MAX_POSTGRADSTUDENT_GPA)
	private float gpa;
	
	// constructor methods
	/**
	 * @effect <pre>
	 * 			if id, name, phoneNumber, address, gpa are valid
	 * 				initialize this as PostgradStudent:<id, name, phoneNumber, address, gpa>
	 * 			else
	 * 				throws NotPossibleException
	 * 			</pre>
	 */
	public PostgradStudent(
			@AttrRef("id") int id, 
			@AttrRef("name") String name, 
			@AttrRef("phoneNumber") String phoneNumber, 
			@AttrRef("address") String address,
			@AttrRef("gpa") float gpa) throws NotPossibleException {
		super(id, name, phoneNumber, address);
		if (!validateGpa(gpa))
			throw new NotPossibleException("PostgradStudent.init: Invalid gpa: " + gpa);
		this.gpa = gpa;
	}

	// methods
	/**
	 * @effects return <tt>this.gpa</tt>
	 */
	@DOpt(type = OptType.Observer) @AttrRef("gpa")
	public float getGpa() {
		return gpa;
	}

	/**
	 * @effects <pre>
	 * 			if gpa is valid
	 * 				set this.gpa = gpa
	 * 				return true
	 * 			else
	 * 				return false
	 * 			</pre>
	 */
	@DOpt(type = OptType.Mutator) @ AttrRef("gpa")
	public boolean setGpa(float gpa) {
		if (validateGpa(gpa)){
			this.gpa = gpa;
			return true;
		}
		else
			return false;
	}

	/**
	 * @effects <pre>
	 * 			return a string representation of this object
	 * 			</pre>
	 */
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder("PostgradStudent: <");
    	sb.append("Id: ").append(getId()).append(", ")
  .append("Name: ").append(getName()).append(", ")
    	  .append("Phone Number: ").append(getPhoneNumber()).append(", ")
    	  .append("Address: ").append(getAddress()).append(">");
    	return sb.toString();
	}
  
  /**
   * @effects <pre>
   * 			if this satisfies rep invariant
   * 				return true
   * 			else
   * 				return false
   * 			</pre>
   */
  @Override
  public boolean repOK() {
    return super.repOK() && validateGpa(gpa);
  } 
	/**
	 * @effects <pre>
	 * 			if id is valid
	 * 				return true
	 * 			else
	 * 				return false
	 * 			</pre>
	 */
	@Override
	@DomainConstraint(type = "Integer", mutable = false, optional = false, min = MIN_POSTGRADSTUDENT_GPA, max = MAX_POSTGRADSTUDENT_ID)
	protected boolean validateId(int id) {
		if (!super.validateId(id))
			return false;
		
		if (id < MIN_POSTGRADSTUDENT_ID || id > MAX_POSTGRADSTUDENT_ID)
			return false;
		else
			return true;
	}
	
	/**
	 * @effects <pre>
	 * 			if o is null
	 * 				return false
	 * 			else if o is not an instance of PostgradStudent
	 * 				return false
	 * 			else
	 * 				return this.id = o.id
	 * 			</pre>
	 */
	public int compareTo(Student o) {
		return super.compareTo(o);
	}

	/**
	 * @effects <pre>
	 * 			if gpa is valid
	 * 				return true
	 * 			else
	 * 				return false
	 * 			</pre>
	 */
	private boolean validateGpa(float gpa) {
		if (gpa < MIN_POSTGRADSTUDENT_GPA || gpa > MAX_POSTGRADSTUDENT_GPA)
			return false;
		else
			return true;
	}
  
  @Override
	/**
   * @effects <pre>
   *      return a simple HTML document generated from the state of the current object
   *      </pre>
   */
  
    public String toHtmlDoc() {
        return "<html>\n" +
                "<head><title>PostgradStudent:" + getId() + "-" + getName() + "</title></head>\n" +
                "<body>\n" +
                getId() + " " + getName() + " " + getPhoneNumber() + " " + getAddress() + " " + getGpa() + "\n" +
                "</body></html>";
    }
}

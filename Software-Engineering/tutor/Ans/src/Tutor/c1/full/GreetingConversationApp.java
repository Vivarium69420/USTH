package tutor.c1.full;

import utils.NotPossibleException;

/**
 * @overview
 *  A program that demonstrates how to use {@link Person} and {@link MobilePhone}.
 */

public class GreetingConversationApp {
	public static void main(String[] args) {
		MobilePhone m1 = null;
		MobilePhone m2 = null;
		try {
			m1 = new MobilePhone("Realme", "Realme Q", 'X', 2014);
			System.out.print("Created " + m1);
		} catch (NotPossibleException e) {
			System.err.println("-> Failed to create MobilePhone");
			e.printStackTrace();
		}
		
		try {
			m2 = new MobilePhone("Realme", "Realme Pro 5", 'R', 2014);
			System.out.print("Created " + m2);
		} catch (NotPossibleException e) {
			System.err.println(" -> Failed to create MobilePhone");
			e.printStackTrace();
		} 
		System.out.println();
		try {
			Person p1 = new Person(10, "James");
			System.out.println("Created " + p1);
			p1.setPhone(m2);
			System.out.print(" has phone " + p1.getPhone());
		} catch(NotPossibleException e) {
			System.err.println("-> Failed to 'create' Person");
			e.printStackTrace();
		}
		
	}
}

// Muhammad Huzaifa Awan | 09-131242-060 | Variant A
import java.util.ArrayList;
 
public class Main {
    static void show(String label, boolean actual) {
        System.out.println(label + " -> " + actual);
    }
 
    public static void main(String[] args) {
        BookingDesk desk = new BookingDesk();
        // First equipment id = "E" + last two digits of roll number (E + last two digits of roll no 09-131242-060)
        desk.addEquipment(new Equipment("E60", "Oscilloscope", "Electronics"));
        desk.addEquipment(new Equipment("E01", "Laptop", "Computing"));
        desk.addEquipment(new Equipment("E02", "Router", "Networking"));
        desk.addEquipment(new Equipment("E03", "Raspberry Pi", "Computing"));
 
        System.out.println("=== Inventory ===");
        desk.printInventory();
 
        System.out.println("\n=== Tests (see TestPlan.txt) ===");
        show("T1 Huzaifa books E60 for 3h (valid)", desk.bookEquipment("Huzaifa", "E60", 3));
        show("T2 Sara books E60 (already booked)", desk.bookEquipment("Sara", "E60", 2));
        show("T3 Sara books E99 (id does not exist)", desk.bookEquipment("Sara", "E99", 2));
        show("T4 Sara books E01 for 5h (over MAX_HOURS)", desk.bookEquipment("Sara", "E01", 5));
        show("T5 Sara books E01 for 0h (below 1)", desk.bookEquipment("Sara", "E01", 0));
        show("T6 Huzaifa books E01 for 2h (2nd booking, valid)", desk.bookEquipment("Huzaifa", "E01", 2));
        show("T7 Huzaifa books E02 for 1h (3rd booking, over MAX_ACTIVE)", desk.bookEquipment("Huzaifa", "E02", 1));
        show("T8 Return E60 (exists)", desk.returnEquipment("E60"));
        show("T9 Return E60 again (no booking)", desk.returnEquipment("E60"));
        show("T10 Huzaifa books E02 for 1h (after return, valid)", desk.bookEquipment("Huzaifa", "E02", 1));
 
        System.out.println("\n=== Current bookings ===");
        desk.printBookings();
 
        System.out.println("\n=== C4: findAvailableByCategory(\"computing\") ===");
        ArrayList<Equipment> free = desk.findAvailableByCategory("computing");
        for (Equipment e : free) {
            System.out.println(e);
        }
        System.out.println("=== C4: findAvailableByCategory(\"Robotics\") (none) ===");
        System.out.println(desk.findAvailableByCategory("Robotics"));
    }
}
 

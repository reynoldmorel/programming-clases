package monegros.restaurant.entities.repository.implementation;

import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.Employee;
import monegros.restaurant.entities.repository.IEmployeeRepository;

public class EmployeeRepository implements IEmployeeRepository{
	private final Set<Employee> myEmployees = new HashSet<>();
	
	@Override
    public Optional<Employee> insert(Employee employee) {
        this.myEmployees.add(employee);
        return Optional.of(employee);
    }
	
	@Override
    public Optional<Employee> update(Employee employee) {
        Employee existing = myEmployees.stream()
                .filter(c -> c.equals(employee))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The employee you are trying to update does not exist"));

        existing.setAddress(employee.getAddress());
        existing.setAge(employee.getAge());
        existing.setName(employee.getName());
        existing.setLastName(employee.getLastName());
        existing.setPhone(employee.getPhone());

        return Optional.of(existing);
    }
	@Override
    public Optional<Boolean> delete(Long id) {
        Employee employeeToDelete = new Employee(id);
        myEmployees.removeIf(c -> c.equals(employeeToDelete));
        return Optional.of(Boolean.TRUE);
    }
	@Override
    public Optional<Employee> findById(Long id) {
    	Employee existing = myEmployees.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Employee you are trying to find does not exist"));

        return Optional.of(existing);
    }

}

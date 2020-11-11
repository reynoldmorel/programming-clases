package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.Employee;
import monegros.restaurant.entities.repository.IEmployeeRepository;
import monegros.restaurant.services.interfaces.IEmployeeService;

public class EmployeeServiceImpl implements IEmployeeService{
private final IEmployeeRepository employeeRepository;
	
	public EmployeeServiceImpl(IEmployeeRepository employeeRepository) {
		this.employeeRepository=employeeRepository;
	}
	@Override
	public Optional<Employee> insert(Employee employee) {
		return this.employeeRepository.insert(employee);
	}
	@Override
	public Optional<Employee> findById(Long id) {
		return this.employeeRepository.findById(id);
	}
}

package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.Employee;

public interface IEmployeeService {
	Optional<Employee> insert(Employee employee);

	Optional<Employee> findById(Long id);
}

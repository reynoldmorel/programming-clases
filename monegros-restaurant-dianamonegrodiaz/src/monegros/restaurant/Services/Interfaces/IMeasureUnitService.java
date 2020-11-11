package monegros.restaurant.services.interfaces;

import java.util.Optional;
import monegros.restaurant.entities.MeasureUnit;

public interface IMeasureUnitService {
	Optional<MeasureUnit> insert(MeasureUnit cashier);
	Optional<MeasureUnit> findById(Long id);
}

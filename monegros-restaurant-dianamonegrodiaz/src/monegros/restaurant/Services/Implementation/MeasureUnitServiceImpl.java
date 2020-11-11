package monegros.restaurant.services.implementation;

import java.util.Optional;
import monegros.restaurant.entities.MeasureUnit;
import monegros.restaurant.entities.repository.IMeasurementUnitRepository;
import monegros.restaurant.services.interfaces.IMeasureUnitService;

public class MeasureUnitServiceImpl implements IMeasureUnitService {
	private final IMeasurementUnitRepository measureUnitRepository;

	public MeasureUnitServiceImpl(IMeasurementUnitRepository measureUnitRepository) {
		this.measureUnitRepository = measureUnitRepository;
	}

	@Override
	public Optional<MeasureUnit> insert(MeasureUnit measureUnit) {
		return this.measureUnitRepository.insert(measureUnit);
	}

	@Override
	public Optional<MeasureUnit> findById(Long id) {
		return this.measureUnitRepository.findById(id);
	}
}

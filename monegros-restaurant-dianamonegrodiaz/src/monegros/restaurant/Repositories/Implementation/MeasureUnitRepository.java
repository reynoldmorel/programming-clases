package monegros.restaurant.entities.repository.implementation;

import java.time.Instant;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import monegros.restaurant.entities.MeasureUnit;
import monegros.restaurant.entities.repository.IMeasurementUnitRepository;

public class MeasureUnitRepository implements IMeasurementUnitRepository{
	private final Set<MeasureUnit> myMeasureUnits = new HashSet<>();

    @Override
    public Optional<MeasureUnit> insert(MeasureUnit measureUnit) {
        measureUnit.setId(Instant.now().toEpochMilli());
        this.myMeasureUnits.add(measureUnit);
        return Optional.of(measureUnit);
    }

    @Override
    public Optional<MeasureUnit> update(MeasureUnit measureUnit) {
        MeasureUnit existing = myMeasureUnits.stream()
                .filter(c -> c.equals(measureUnit))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Measure Unit you are trying to update does not exist"));
        existing.setName(measureUnit.getName());

        return Optional.of(existing);
    }
    @Override
    public Optional<Boolean> delete(Long id) {
        MeasureUnit measureUnitToDelete = new MeasureUnit(id);
        myMeasureUnits.removeIf(c -> c.equals(measureUnitToDelete));

        return Optional.of(Boolean.TRUE);
    }
    @Override
    public Optional<MeasureUnit> findById(Long id) {
    	MeasureUnit existing =myMeasureUnits.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("The Measure Unit you are trying to find does not exist"));

        return Optional.of(existing);
    }
}

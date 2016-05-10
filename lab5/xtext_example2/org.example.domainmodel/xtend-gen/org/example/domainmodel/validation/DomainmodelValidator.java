/**
 * generated by Xtext 2.9.2
 */
package org.example.domainmodel.validation;

import com.google.common.base.Objects;
import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.validation.Check;
import org.example.domainmodel.domainmodel.DomainmodelPackage;
import org.example.domainmodel.domainmodel.Entity;
import org.example.domainmodel.domainmodel.Feature;
import org.example.domainmodel.validation.AbstractDomainmodelValidator;

/**
 * This class contains custom validation rules.
 * 
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#validation
 */
@SuppressWarnings("all")
public class DomainmodelValidator extends AbstractDomainmodelValidator {
  @Check
  public void checkNameStartsWithCapital(final Entity entity) {
    String _name = entity.getName();
    char _charAt = _name.charAt(0);
    boolean _isUpperCase = Character.isUpperCase(_charAt);
    boolean _not = (!_isUpperCase);
    if (_not) {
      this.warning("Name should start with a capital", 
        DomainmodelPackage.Literals.TYPE__NAME);
    }
  }
  
  @Check
  public void checkFeatureNameIsUnique(final Feature f) {
    EObject _eContainer = f.eContainer();
    Entity superEntity = ((Entity) _eContainer).getSuperType();
    while ((!Objects.equal(superEntity, null))) {
      {
        EList<Feature> _features = superEntity.getFeatures();
        for (final Feature other : _features) {
          String _name = f.getName();
          String _name_1 = other.getName();
          boolean _equals = Objects.equal(_name, _name_1);
          if (_equals) {
            this.error("Feature names have to be unique", 
              DomainmodelPackage.Literals.FEATURE__NAME);
            return;
          }
        }
        Entity _superType = superEntity.getSuperType();
        superEntity = _superType;
      }
    }
  }
}

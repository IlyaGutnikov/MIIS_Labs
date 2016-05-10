package org.example.domainmodel.generator
 
import org.eclipse.emf.ecore.resource.Resource
import org.eclipse.xtext.generator.IGenerator
import org.eclipse.xtext.generator.IFileSystemAccess
import org.example.domainmodel.domainmodel.Entity
import org.example.domainmodel.domainmodel.Feature
import org.eclipse.xtext.naming.IQualifiedNameProvider
 
import com.google.inject.Inject
 
class DomainmodelGenerator implements IGenerator {
 
    @Inject extension IQualifiedNameProvider
 
    override void doGenerate(Resource resource, IFileSystemAccess fsa) {
        for (e : resource.allContents.toIterable.filter(Entity)) {
            fsa.generateFile(
                e.fullyQualifiedName.toString("/") + ".java",
                e.compile)
        }
    }
 
    def compile(Entity e) ''' 
        «IF e.eContainer.fullyQualifiedName != null»
            package «e.eContainer.fullyQualifiedName»;
        «ENDIF»
        
        public class «e.name» «IF e.superType != null
                »extends «e.superType.fullyQualifiedName» «ENDIF»{
            «FOR f : e.features»
                «f.compile»
            «ENDFOR»
        }
    '''
 
    def compile(Feature f) '''
        private «f.type.fullyQualifiedName» «f.name»;
        
        public «f.type.fullyQualifiedName» get«f.name.toFirstUpper»() {
            return «f.name»;
        }
        
        public void set«f.name.toFirstUpper»(«f.type.fullyQualifiedName» «f.name») {
            this.«f.name» = «f.name»;
        }
    '''
}
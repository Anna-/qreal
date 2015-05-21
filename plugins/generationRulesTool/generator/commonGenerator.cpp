#include "commonGenerator.h"

#include "generatorForProgramNode.h"
#include "generatorForComplexIdentifierNode.h"
#include "generatorForForeachNode.h"
#include "generatorForCallGenerator.h"
#include "generatorForGeneratorNode.h"
#include "generatorForGenerateToFile.h"
#include "generatorForIfNode.h"

#include "ast/program.h"
#include "ast/complexIdentifier.h"
#include "ast/foreach.h"
#include "ast/identifier.h"
#include "ast/newline.h"
#include "ast/text.h"
#include "ast/callGeneratorFor.h"
#include "ast/generator.h"
#include "ast/tab.h"
#include "ast/ifNode.h"

using namespace generationRules::generator;
using namespace simpleParser;

QString CommonGenerator::generatedResult(QSharedPointer<ast::Node> node
		, GeneratorConfigurer generatorConfigurer)
{
	QString result = "";

	if (node->is<ast::Program>()) {
		QSharedPointer<ast::Program> program = qrtext::as<ast::Program>(node);
		result = GeneratorForProgramNode::generatedResult(program, generatorConfigurer);
	}
	else if (node->is<ast::ComplexIdentifier>()) {
		QSharedPointer<ast::ComplexIdentifier> complexIdentifier = qrtext::as<ast::ComplexIdentifier>(node);
		result = GeneratorForComplexIdentifierNode::generatedResult(complexIdentifier, generatorConfigurer).toString();
	}
	else if (node->is<ast::Foreach>()) {
		QSharedPointer<ast::Foreach> foreachNode = qrtext::as<ast::Foreach>(node);
		result = GeneratorForForeachNode::generatedResult(foreachNode, generatorConfigurer);
	}
	else if (node->is<ast::CallGeneratorFor>()) {
		QSharedPointer<ast::CallGeneratorFor> callGeneratorNode = qrtext::as<ast::CallGeneratorFor>(node);
		result = GeneratorForCallGenerator::generatedResult(callGeneratorNode, generatorConfigurer);
	}
	else if (node->is<ast::GenerateToFile>()) {
		QSharedPointer<ast::GenerateToFile> generateToFileNode = qrtext::as<ast::GenerateToFile>(node);
		result = GeneratorForGenerateToFile::generatedResult(generateToFileNode, generatorConfigurer);
	}
	else if (node->is<ast::Generator>()) {
		QSharedPointer<ast::Generator> generatorNode = qrtext::as<ast::Generator>(node);
		result = GeneratorForGeneratorNode::generatedResult(generatorNode, generatorConfigurer);
	}
	else if (node->is<ast::IfNode>()) {
		QSharedPointer<ast::IfNode> ifNode = qrtext::as<ast::IfNode>(node);
		result = GeneratorForIfNode::generatedResult(ifNode, generatorConfigurer);
	}
	else if (node->is<ast::Newline>()) {
		result = "\n";
	}
	else if (node->is<ast::Text>()) {
		QSharedPointer<ast::Text> text = qrtext::as<ast::Text>(node);
		result = text->text();
	}
	else if (node->is<ast::Tab>()) {
		result += "	";
	}
	else {
		qDebug() << "Something went wrong";
	}

	return result;
}

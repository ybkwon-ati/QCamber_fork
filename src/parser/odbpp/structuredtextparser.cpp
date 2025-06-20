/**
 * @file   structuredtextparser.cpp
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2012 - 2014 Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "structuredtextparser.h"

#include <QDebug>
#include <fstream>
#include <string>

#include "yyheader.h"
#include "db.tab.h"

extern struct yycontext yyctx;
extern int yyparse (void);
extern FILE* yyin;

StructuredTextParser::StructuredTextParser(const QString& filename):
  Parser(filename)
{
#ifdef Q_OS_WIN
  m_fileName.replace("/", "\\");
#endif
}

StructuredTextParser::~StructuredTextParser()
{
}

StructuredTextDataStore* StructuredTextParser::parse(void)
{
#ifdef _WIN32
  std::wstring wpath = m_fileName.toStdWString();
  yyin = _wfopen(wpath.c_str(), L"r");
#else
  yyin = fopen(m_fileName.toStdString().c_str(), "r");
#endif

  if (yyin == NULL) {
    qDebug("parse: can't open `%s' for reading", qPrintable(m_fileName));
    return NULL;
  }

  yyctx.stds = new StructuredTextDataStore;
  yyparse();

  return yyctx.stds;
}

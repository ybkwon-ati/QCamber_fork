/**
 * @file   notesparser.cpp
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

#include "notesparser.h"

#include <fstream>
#include <string>

NotesParser::NotesParser(const QString& filename): Parser(filename)
{
}

NotesParser::~NotesParser()
{
}

NotesDataStore* NotesParser::parse(void)
{
#ifdef _WIN32
  std::wifstream file(m_fileName.toStdWString());
#else
  std::ifstream file(m_fileName.toStdString());
#endif
  if (!file.is_open()) {
    qDebug("parse: can't open `%s' for reading", qPrintable(m_fileName));
    return NULL;
  }

  NotesDataStore* ds = new NotesDataStore;
#ifdef _WIN32
  std::wstring wline;
  while (std::getline(file, wline)) {
    QString line = QString::fromStdWString(wline);
#else
  std::string sline;
  while (std::getline(file, sline)) {
    QString line = QString::fromStdString(sline);
#endif
    ds->putRecord(line.split(","));
  }

  return ds;
}


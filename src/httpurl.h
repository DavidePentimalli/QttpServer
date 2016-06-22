#ifndef QTTPHTTPURL_H
#define QTTPHTTPURL_H

#include "qttp_global.h"

namespace qttp
{

class HttpData;
class HttpRequest;
class HttpResponse;

/**
 * @brief The HttpUrl class
 *
 * TODO: Still need to figure out if we can optimize mem usage.
 */
class QTTPSHARED_EXPORT HttpUrl
{
    friend class HttpData;
    friend class HttpRequest;
    friend class HttpResponse;

  private:
    HttpUrl(native::http::request* req);

  public:
    ~HttpUrl();

    /**
     * @brief This defeats the purpose of lazily initializing members.
     */
    void initialize();

    const QString& getSchema() const;
    const QString& getHost() const;
    qint32 getPort() const;
    const QString& getPath() const;
    const QString& getQuery() const;
    const QString& getFragment() const;

  private:
    Assert<native::http::request> m_Assertion;
    const native::http::request* m_Request;

    /// Mutable because this is inteded to help cache and reduce QString conversions.
    mutable QSharedPointer<QString> m_Schema;

    /// Mutable because this is inteded to help cache and reduce QString conversions.
    mutable QSharedPointer<QString> m_Host;

    /// Mutable because this is inteded to help cache and reduce QString conversions.
    mutable QSharedPointer<QString> m_Path;

    /// Mutable because this is inteded to help cache and reduce QString conversions.
    mutable QSharedPointer<QString> m_Query;

    /// Mutable because this is inteded to help cache and reduce QString conversions.
    mutable QSharedPointer<QString> m_Fragment;
};

}

#endif // QTTPHTTPURL_H
